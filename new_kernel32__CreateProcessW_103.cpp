static BOOL WINAPI _new_kernel32__CreateProcessW_103(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation) {
	BOOL retV;
	BOOL isSuspended;

	isSuspended=((dwCreationFlags&CREATE_SUSPENDED)==CREATE_SUSPENDED);
	retV=XYO::Win::Inject::Process::createProcessW(
		     (WCHAR *)lpApplicationName,
		     (WCHAR *)lpCommandLine,
		     lpProcessAttributes,
		     lpThreadAttributes,
		     bInheritHandles,
		     dwCreationFlags|CREATE_SUSPENDED,
		     lpEnvironment,
		     (WCHAR *)lpCurrentDirectory,
		     (LPSTARTUPINFOW)lpStartupInfo,
		     lpProcessInformation,
		     thisModuleFileName
	     );

	if(retV==TRUE) {
		if(!isSuspended) {
			ResumeThread(lpProcessInformation->hThread);
		};
	};

	return retV;
};
