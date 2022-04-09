static BOOL WINAPI _new_advapi32__CreateProcessAsUserW(HANDLE hToken, LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation) {

	// OutputDebugStringA("advapi32.CreateProcessAsUserW");

	// OutputDebugStringXW(L"advapi32.CreateProcessAsUserW1:",(WCHAR *)lpApplicationName);
	// OutputDebugStringXW(L"advapi32.CreateProcessAsUserW2:",(WCHAR *)lpCommandLine);

	// return (*_original_advapi32__CreateProcessAsUserW)(hToken,lpApplicationName,lpCommandLine,lpProcessAttributes,lpThreadAttributes,bInheritHandles,dwCreationFlags,lpEnvironment,lpCurrentDirectory,lpStartupInfo,lpProcessInformation);

	BOOL retV;
	BOOL isSuspended;

	isSuspended = ((dwCreationFlags & CREATE_SUSPENDED) == CREATE_SUSPENDED);
	retV = XYO::Win::Inject::Process::createProcessAsUserW(
	    hToken,
	    (WCHAR *)lpApplicationName,
	    (WCHAR *)lpCommandLine,
	    lpProcessAttributes,
	    lpThreadAttributes,
	    bInheritHandles,
	    dwCreationFlags | CREATE_SUSPENDED,
	    lpEnvironment,
	    (WCHAR *)lpCurrentDirectory,
	    (LPSTARTUPINFOW)lpStartupInfo,
	    lpProcessInformation,
	    thisModuleFileName);

	if (retV == TRUE) {
		if (!isSuspended) {
			ResumeThread(lpProcessInformation->hThread);
		};
	};

	return retV;
};
