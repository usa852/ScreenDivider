#pragma once
class DLLInjector
{
private:

public:
	DLLInjector(void);
	~DLLInjector(void);

	BOOL	Inject(CString szProcessName, CString szDllPath);
	BOOL	Inject(DWORD dwPID, CString szDllPath);
	BOOL	InjectAll(DWORD minimumPID, CString szDllPath);
	BOOL	IsDllInProcess(DWORD dwPID, CString szDllPath);
};