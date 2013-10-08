#include "stdafx.h"

#define FAIL ~0x0

BOOL IsVistaLater();
HANDLE MyCreateRemoteThread
(
	HANDLE					hProcess,
	LPSECURITY_ATTRIBUTES	lpThreadAttributes,
	DWORD					dwStackSize,
	LPTHREAD_START_ROUTINE	lpStartAddress,
	LPVOID					lpParameter,
	DWORD					dwCreationFlags,
	LPDWORD					lpThreadId
);
DWORD FindPID(CString szProcessName);