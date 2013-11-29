
// ScreenDividerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "ScreenDividerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UID_TRAY 0
#define TM_NOTIFICATION (WM_APP + 1)

/* Export calls */
// Hook start
typedef BOOL (*PFN_STARTWNDPROCHOOK)();
BOOL InstallHook()
{
	BOOL isSuccess = TRUE;

	// Load library to get address of procedure('StartWndProcHook()')
	HMODULE hModule;
#ifdef _X64
	hModule = LoadLibrary(L"ScreenDividerHk64.dll");
#else
	hModule = LoadLibrary(L"ScreenDividerHk32.dll");
#endif
	if (hModule == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Get address of 'StartWndProcHook()'
	PFN_STARTWNDPROCHOOK StartWndProcHook = NULL;
	StartWndProcHook = (PFN_STARTWNDPROCHOOK)GetProcAddress(hModule, "StartWndProcHook");
	if (StartWndProcHook == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Call StartWndProcHook() got top
	StartWndProcHook();

EXIT:
	if (hModule != NULL)
	{
		FreeLibrary(hModule);
	}

	return isSuccess;
}

// Refresh dll's data
typedef BOOL (*PFN_REFRESHSDFORM)(TCHAR strSDFormPath[MAX_PATH]);
BOOL RefreshSDForm(TCHAR strSDFormPath[MAX_PATH])
{
        BOOL isSuccess = TRUE;

        // Load library to get address of procedure('RefreshSDForm()')
        HMODULE hModule;
#ifdef _X64
        hModule = LoadLibrary(L"ScreenDividerHk64.dll");
#else
        hModule = LoadLibrary(L"ScreenDividerHk32.dll");
#endif
        if (hModule == NULL)
        {
                isSuccess = FALSE;
                goto EXIT;
        }

        // Get address of 'RefreshSDForm()'
        PFN_REFRESHSDFORM RefreshSDForm = NULL;
        RefreshSDForm = (PFN_REFRESHSDFORM)GetProcAddress(hModule, "RefreshSDForm");
        if (RefreshSDForm == NULL)
        {
                isSuccess = FALSE;
                goto EXIT;
        }

        // Call RefreshSDForm() got top
        RefreshSDForm(strSDFormPath);

EXIT:
        if (hModule != NULL)
        {
                FreeLibrary(hModule);
        }

        return isSuccess;
}

// CScreenDividerDlg dialog.
CScreenDividerDlg::CScreenDividerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenDividerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScreenDividerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CScreenDividerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(TM_NOTIFICATION, OnTrayNotification)
	ON_COMMAND(ID_TRAYMENU_QUIT, &CScreenDividerDlg::OnTraymenuQuit)
	ON_COMMAND(ID_TRAYMENU_EDITOR, &CScreenDividerDlg::OnTraymenuEditor)
	ON_COMMAND(ID_TRAYMENU_SETTINGS, &CScreenDividerDlg::OnTraymenuSettings)
	ON_WM_WINDOWPOSCHANGING()
	ON_COMMAND(ID_TRAYMENU_OPEN, &CScreenDividerDlg::OnTraymenuOpen)
END_MESSAGE_MAP()


// CScreenDividerDlg message handlers

BOOL CScreenDividerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Create tray icon
	ZeroMemory(&m_nid, sizeof(m_nid));
	m_nid.cbSize = sizeof(NOTIFYICONDATA);
	m_nid.hWnd = GetSafeHwnd();
	m_nid.uID = UID_TRAY;
	m_nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	m_nid.uCallbackMessage = TM_NOTIFICATION;
	m_nid.hIcon = m_hIcon;
	lstrcpy(m_nid.szTip, L"ScreenDivider");
	Shell_NotifyIcon(NIM_ADD, &m_nid);

	// Initialize some variables
	m_strSDFormPath = L"";
	m_isHooked = FALSE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CScreenDividerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScreenDividerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CScreenDividerDlg::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case WM_RBUTTONDOWN:
		CPoint point;
		GetCursorPos(&point);

		CMenu menuTray;
		menuTray.LoadMenu(IDR_MENU_TRAY);

		CMenu *pFirstMenu;
		pFirstMenu = menuTray.GetSubMenu(0);
		pFirstMenu->TrackPopupMenu
		(
			TPM_LEFTALIGN | TPM_RIGHTBUTTON,
			point.x, point.y,
			AfxGetMainWnd()
		);
		break;
	}

	return TRUE;
}

BOOL CScreenDividerDlg::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	// Destroy tray icon
	Shell_NotifyIcon(NIM_DELETE, &m_nid);

	return CDialogEx::DestroyWindow();
}

void CScreenDividerDlg::OnTraymenuQuit()
{
	// TODO: Add your command handler code here
	EndDialog(IDCANCEL);
}


void CScreenDividerDlg::OnTraymenuEditor()
{
	// TODO: Add your command handler code here
	if (m_dlgEditor.DoModal() == IDOK)
	{
		// Refresh sdform datas in dll
		BOOL ret;
		ret = RefreshSDForm((TCHAR *)(LPCTSTR)m_strSDFormPath);
		if (!ret)
		{
			AfxMessageBox(L"Can't open the SDForm file\n"
							L"Please retry later", MB_OK | MB_ICONSTOP);
		}
	}
}

void CScreenDividerDlg::OnTraymenuSettings()
{
	// TODO: Add your command handler code here
	if (m_dlgSetting.DoModal() == IDOK)
	{
		// Some refresh processing
	}
}


void CScreenDividerDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// Hide this dialog
	// Because of this dialog is main dialog,
	// ShowWindow() function is not performed.
	lpwndpos->flags &= ~SWP_SHOWWINDOW;
}


void CScreenDividerDlg::OnTraymenuOpen()
{
	// TODO: Add your command handler code here
	CFileDialog dlgFileOpen(TRUE, NULL, NULL, 0, L"SDForm Files(*.sdf)|*.sdf||");
	if (dlgFileOpen.DoModal() == IDOK)
	{
		// Load datas
		m_strSDFormPath = dlgFileOpen.GetPathName();
		m_sdForm.LoadFromFile((TCHAR *)(LPCTSTR)m_strSDFormPath);

		// Install hook
		if (!m_isHooked)
		{
			m_isHooked = InstallHook();
			if (!m_isHooked)
			{
				AfxMessageBox(L"Can't open the SDForm file\n"
							  L"Please retry later", MB_OK | MB_ICONSTOP);
			}
		}

		// Refresh sdform datas in dll
		BOOL ret;
		ret = RefreshSDForm((TCHAR *)(LPCTSTR)m_strSDFormPath);
		if (!ret)
		{
			AfxMessageBox(L"Can't open the SDForm file\n"
							L"Please retry later", MB_OK | MB_ICONSTOP);
		}
	}
}
