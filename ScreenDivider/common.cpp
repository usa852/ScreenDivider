#include "stdafx.h"
#include "common.h"
#include "ntdll.h"
#include <TlHelp32.h>

BOOL IsVistaLater()
{
	OSVERSIONINFO osvi;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);

	if(6 <= osvi.dwMajorVersion)	// Vista later version is 6
	{
		return TRUE;
	}

	return FALSE;
}

/*
	Because of windows' changing about management policy of session
	we should process CreateRemoteThread() function to divide before XP and later VISTA.
	SHIT!!
*/
HANDLE MyCreateRemoteThread
(
	HANDLE					hProcess,
	LPSECURITY_ATTRIBUTES	lpThreadAttributes,
	DWORD					dwStackSize,
	LPTHREAD_START_ROUTINE	lpStartAddress,
	LPVOID					lpParameter,
	DWORD					dwCreationFlags,
	LPDWORD					lpThreadId
)
{
	HANDLE hThread = NULL;
	if(IsVistaLater())	// Vista, 7, Server2008
	{
		// Get handle of 'ntdll.dll' that has NtCreateThreadEx() native API
		HMODULE	hModule = NULL;
		hModule = GetModuleHandle(L"ntdll.dll");

		// Get address of NtCreateThreadEx() native API
		FARPROC	pFunc = NULL;
		pFunc = GetProcAddress(hModule, "NtCreateThreadEx");
		if(pFunc == NULL)
		{
			goto EXIT;
		}

		// Call NtCreateThreadEx() native API
		((PFNTCREATETHREADEX)pFunc)
		(
			&hThread,
			0x1FFFFF,
			NULL,
			hProcess,
			lpStartAddress,
			lpParameter,
			FALSE,
			NULL,
			NULL,
			NULL,
			NULL
		);
		if(hThread == NULL)
		{
			goto EXIT;
		}
	}
	else	// 2000, XP, Server2003
	{
		// Call pThreadProc() function
		hThread = CreateRemoteThread
		(
			hProcess,
			lpThreadAttributes,
			dwStackSize,
			lpStartAddress,
			lpParameter,
			dwCreationFlags,
			lpThreadId
		);
		if(hThread == NULL)
		{
			goto EXIT;
		}
	}

EXIT:
	return hThread;
}

DWORD FindPID(CString szProcessName)
{
	DWORD	dwPID		= FAIL;
	HANDLE	hSnapshot	= INVALID_HANDLE_VALUE;

	PROCESSENTRY32	pe;

	// Get the snapshot of the system
	pe.dwSize = sizeof(PROCESSENTRY32);
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		goto EXIT;
	}

	// Set pe to first process
	Process32First(hSnapshot, &pe);

	// Loop all processes
	do
	{
		if (!szProcessName.Compare(pe.szExeFile))
		{
			dwPID = pe.th32ProcessID;
			break;
		}
	}while (Process32Next(hSnapshot, &pe));

EXIT:
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hSnapshot);
	}

	return dwPID;
}

CString GetProcessName(DWORD dwPID)
{
	CString szProcessName;

	// Get the snapshot of system
	PROCESSENTRY32	pe;
	HANDLE			hSnapshot = INVALID_HANDLE_VALUE;
	pe.dwSize = sizeof(PROCESSENTRY32);
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		goto EXIT;
	}

	// Set pe to first process
	Process32First(hSnapshot, &pe);

	// Loop all processes
	do
	{
		if (pe.th32ProcessID == dwPID)
		{
			szProcessName.Format(L"%s", pe.szExeFile);
		}
	}while (Process32Next(hSnapshot, &pe));

EXIT:
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hSnapshot);
	}

	return szProcessName;
}