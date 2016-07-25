static BOOL WINAPI _new_kernel32__CreateProcessA(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation){

	//return (*_original_kernel32__CreateProcessA)(lpApplicationName,lpCommandLine,lpProcessAttributes,lpThreadAttributes,bInheritHandles,dwCreationFlags,lpEnvironment,lpCurrentDirectory,lpStartupInfo,lpProcessInformation);

	BOOL retV;
	BOOL isSuspended;

	isSuspended=((dwCreationFlags&CREATE_SUSPENDED)==CREATE_SUSPENDED);
	retV=XYO::Win::Inject::Process::createProcessA(
		     lpApplicationName,
		     lpCommandLine,
		     lpProcessAttributes,
		     lpThreadAttributes,
		     bInheritHandles,
		     dwCreationFlags|CREATE_SUSPENDED,
		     lpEnvironment,
		     lpCurrentDirectory,
		     lpStartupInfo,
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
