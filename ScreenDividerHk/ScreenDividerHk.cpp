// ScreenDividerHk.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "ScreenDividerHk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// The one and only CScreenDividerHkApp object
CScreenDividerHkApp theApp;

// Hook procedures
LRESULT WINAPI CallWndProc(int nCode, WPARAM wParam, LPARAM lParam);

// ScreenDivider messages
#define SDM_CREATEWINDOW	(WM_USER + 1)
#define SDM_DESTROYWINDOW	(WM_USER + 2)

// Global variables
ULARGE_INTEGER g_timeLastModified = {0, };
HHOOK g_hHook;
BOOL isInTitleBar;
CSDForm g_sdForm;
CSDWindow g_curSDWindow;

// Extern functions
extern "C"
{
	__declspec(dllexport) BOOL StartWndProcHook(HWND hParent)
	{
		BOOL isSuccess = TRUE;

		// Put ScreenDivider's window handle to send message
		s_hWndSD = hParent;

		// Add hook procedure to hook chain
		HHOOK hHook;
		hHook = SetWindowsHookEx(WH_CALLWNDPROC, CallWndProc, theApp.m_hInstance, 0);
		if (hHook == NULL)
		{
			isSuccess = FALSE;
			goto EXIT;
		}
		
		// Save hook handle for using in hook procedure
		g_hHook = hHook;

	EXIT:
		return isSuccess;
	}

	__declspec(dllexport) BOOL RefreshSDForm(TCHAR strSDFormPath[MAX_PATH])
	{
		// Because this part is C type part,
		// variables should be declared in top.
		BOOL isSuccess = TRUE;
		BOOL ret;

		HANDLE hFile = INVALID_HANDLE_VALUE;
		FILETIME timeFile = {0, };

		// Open file
		hFile = CreateFile
				(
					strSDFormPath,			/* lpFileName */
					GENERIC_READ,			/* dwDesiredAccess */
					NULL,					/* dwShareMode */
					NULL,					/* lpSecurityAttributes */
					OPEN_EXISTING,			/* dwCreationDisposition */
					FILE_ATTRIBUTE_NORMAL,	/* dwFlagsAndAttributes */
					NULL
				);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			isSuccess = FALSE;
			goto EXIT;
		}

		// Get file write time
		ret = GetFileTime(hFile, NULL, NULL, &timeFile);
		if (ret == 0)
		{
			isSuccess = FALSE;
			goto EXIT;
		}

		// Refresh g_timeLastModified
		s_timeLastModified.LowPart = timeFile.dwLowDateTime;
		s_timeLastModified.HighPart = timeFile.dwHighDateTime;

		// Check new file is
		if (wcsncmp(strSDFormPath, s_strSDFormPath,
					(wcslen(strSDFormPath) < wcslen(s_strSDFormPath)) ? 
						wcslen(s_strSDFormPath) : 
						wcslen(strSDFormPath)
					)
			)
		{
			// If new file, initialize some datas.
			wsprintf(s_strSDFormPath, strSDFormPath);
			g_timeLastModified.QuadPart = 0;
		}

		{
			TCHAR strRet[MAX_PATH] = {0, };

			wsprintf(strRet, L"%s %d %d\n",
							s_strSDFormPath,
							g_timeLastModified.QuadPart,
							g_timeLastModified.QuadPart
					);
			OutputDebugString(strRet);
		}

	EXIT:
		if (hFile != INVALID_HANDLE_VALUE)
		{
			CloseHandle(hFile);
		}

		return isSuccess;
	}
}

// WH_CALLWNDPROC hook procedure
LRESULT WINAPI CallWndProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	// Do not process message
	if (nCode < 0)
	{
		return CallNextHookEx(g_hHook, nCode, wParam, lParam);
	}

	switch (nCode)
	{
	case HC_ACTION:
		CWPSTRUCT* pCwpParam;
		pCwpParam = (CWPSTRUCT *)lParam;

		switch (pCwpParam->message)
		{
		case WM_MOVING:
		{
			POINT point = {0, 0};
			BOOL ret = 0;

			// Get current mouse position
			ret = GetCursorPos(&point);
			if (ret == 0)
			{
				CString strRet;
				strRet.Format(L"Error: %d\n", GetLastError());

				OutputDebugString(strRet);
				break;
			}

			if (g_timeLastModified.QuadPart < s_timeLastModified.QuadPart)
			{
				// Reload data
				OutputDebugString(L"Reload sdForm file\n");

				// Load sdForm data from file
				g_sdForm.LoadFromFile(s_strSDFormPath);

				// Sync refresh time with modifed time
				g_timeLastModified.QuadPart = s_timeLastModified.QuadPart;
			}

			// Check the cursor come in the title bar
			g_curSDWindow = g_sdForm.GetSDWindow(point);
			if (g_curSDWindow.IsRectNull())
			{
				isInTitleBar = FALSE;

				// Remove virtual window
				SendMessage(s_hWndSD, SDM_DESTROYWINDOW, NULL, NULL);
			}
			else
			{
				if (!isInTitleBar)
				{
					isInTitleBar = TRUE;

					// Get index from SDWindow
					INT_PTR idxSDWindow;
					idxSDWindow = g_sdForm.GetIndexFromSDWindow(g_curSDWindow);

					// Show virtual window
					SendMessage(s_hWndSD, SDM_CREATEWINDOW, FALSE, idxSDWindow);

					{
						CString strRet;
						strRet.Format(L"Onto sdWindow: (%d-%d)x(%d-%d)\n",
										g_curSDWindow.right, g_curSDWindow.left,
										g_curSDWindow.bottom, g_curSDWindow.top);
						OutputDebugString(strRet);
					}
				}
			}
			}
			break;

			case WM_EXITSIZEMOVE:
			{
			if (isInTitleBar)
			{
				OutputDebugString(L"Moving exited\n");

				// Remove virtual window
				SendMessage(s_hWndSD, SDM_DESTROYWINDOW, NULL, NULL);

				// Resize target window to fit sdWindow
				MoveWindow
				(
					pCwpParam->hwnd,
					g_curSDWindow.left,
					g_curSDWindow.top,
					g_curSDWindow.right - g_curSDWindow.left,
					g_curSDWindow.bottom - g_curSDWindow.top,
					TRUE
				);

				// Modify style like maximized
				LONG style;
				style = GetWindowLongPtr(pCwpParam->hwnd, GWL_STYLE);
				style |= WS_MAXIMIZE;
				SetWindowLongPtr(pCwpParam->hwnd, GWL_STYLE, style);

				isInTitleBar = FALSE;
			}
			}
			break;
		}
		break;
	}

	return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CScreenDividerHkApp

BEGIN_MESSAGE_MAP(CScreenDividerHkApp, CWinApp)
END_MESSAGE_MAP()


// CScreenDividerHkApp construction

CScreenDividerHkApp::CScreenDividerHkApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// CScreenDividerHkApp initialization

BOOL CScreenDividerHkApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
