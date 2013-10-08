#include "stdafx.h"
#include "DLLInjector.h"
#include <TlHelp32.h>

DLLInjector::DLLInjector(void)
{
}

BOOL DLLInjector::Inject(CString szProcessName, CString szDllPath)
{
	DWORD	dwPID;
	dwPID = FindPID(szProcessName);
	if (dwPID == FAIL)
	{
		return FALSE;
	}

	return Inject(dwPID, szDllPath);
}

BOOL DLLInjector::Inject(DWORD dwPID, CString szDllPath)
{
	DWORD	ret = 0;
	BOOL	isSuccess	= NULL;

	HANDLE					hProcess	= NULL;
	HANDLE					hThread		= NULL;
	LPVOID					pRemoteBuf	= NULL;
	DWORD					dwBufSize	= (szDllPath.GetLength() + 1) * sizeof(TCHAR);
	LPTHREAD_START_ROUTINE	pThreadProc = NULL;
	HMODULE					hModule		= NULL;

	isSuccess = TRUE;

	// Open process in all access
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
	if (hProcess == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Allocate virtual memory as much as szDllPath size
	pRemoteBuf = VirtualAllocEx(hProcess, NULL, dwBufSize, MEM_COMMIT, PAGE_READWRITE);
	if (pRemoteBuf == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Write szDllPath to allocated memory
	ret = WriteProcessMemory(hProcess, pRemoteBuf, szDllPath, dwBufSize, NULL);
	if (ret == 0)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Get handle of 'kernel32.dll' that has LoadLibraryW() API
	hModule = GetModuleHandle(L"kernel32.dll");
	if (hModule == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Get address of LoadLibraryW() API
	pThreadProc = (LPTHREAD_START_ROUTINE)GetProcAddress(hModule, "LoadLibraryW");
	if (pThreadProc == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Call LoadLibraryA() API
	/*
		Because of windows' changing management policy of session.
		we should process CreateRemoteThread() function to divide before XP and later VISTA.
		SHIT!!
	*/
	hThread = MyCreateRemoteThread(hProcess, NULL, 0, pThreadProc, pRemoteBuf, 0, NULL);
	if (hThread == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Wait for running
	ret = WaitForSingleObject(hThread, INFINITE);
	if (ret == WAIT_FAILED)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Check worked well
	ret = IsDllInProcess(dwPID, szDllPath);
	if (ret == FALSE)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

EXIT:
	if (hThread != NULL)
	{
		CloseHandle(hThread);
	}
	if (pRemoteBuf != NULL)
	{
		VirtualFreeEx(hProcess, pRemoteBuf, 0, MEM_RELEASE);
	}
	if (hProcess != NULL)
	{
		CloseHandle(hProcess);
	}

	if (isSuccess == FALSE)
	{
		CString strError;
		strError.Format(_T("Error occured\nCode : 0x%08x"), GetLastError());
		AfxMessageBox(strError, MB_OK | MB_ICONERROR, 0);
	}

	return isSuccess;
}

BOOL DLLInjector::InjectAll(DWORD minimumPID, CString szDllPath)
{
	BOOL	isSuccess = TRUE;

	// Get the snapshot of the system
	PROCESSENTRY32	pe;
	HANDLE			hSnapshot = INVALID_HANDLE_VALUE;
	pe.dwSize = sizeof(PROCESSENTRY32);
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Set pe to first process
	Process32First(hSnapshot, &pe);

	// Loop all processes
	do
	{
		// For system stability,
		// we just inject when pid is bigger than minimumPID.
		if (minimumPID < pe.th32ProcessID)
		{
			Inject(pe.th32ProcessID, szDllPath);
		}
	}while (Process32Next(hSnapshot, &pe));

EXIT:
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hSnapshot);
	}

	return isSuccess;
}

BOOL DLLInjector::IsDllInProcess(DWORD dwPID, CString szDllPath)
{
	BOOL	isSuccess = FALSE;

	// Get the snapshot of system
	HANDLE	hSnapshot = INVALID_HANDLE_VALUE;
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Set me to first module
	MODULEENTRY32	me;
	me.dwSize = sizeof(MODULEENTRY32);
	Module32First(hSnapshot, &me);

	// Loop all modules
	do
	{
		if (!szDllPath.Compare(me.szExePath))
		{
			isSuccess = TRUE;
			break;
		}
	}while (Module32Next(hSnapshot, &me));

EXIT:
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hSnapshot);
	}

	return isSuccess;
}

DLLInjector::~DLLInjector(void)
{
}
