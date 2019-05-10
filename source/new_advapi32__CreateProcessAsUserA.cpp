static BOOL WINAPI _new_advapi32__CreateProcessAsUserA(HANDLE hToken, LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{

	//OutputDebugStringA("advapi32.CreateProcessAsUserA");

	//OutputDebugStringXA("advapi32.CreateProcessAsUserA1:",lpApplicationName);
	//OutputDebugStringXA("advapi32.CreateProcessAsUserA2:",lpCommandLine);

	//return (*_original_advapi32__CreateProcessAsUserA)(lpApplicationName,lpCommandLine,lpProcessAttributes,lpThreadAttributes,bInheritHandles,dwCreationFlags,lpEnvironment,lpCurrentDirectory,lpStartupInfo,lpProcessInformation);

	BOOL retV;
	BOOL isSuspended;

	isSuspended = ((dwCreationFlags & CREATE_SUSPENDED) == CREATE_SUSPENDED);
	retV = XYO::Win::Inject::Process::createProcessAsUserA(
			hToken,
			lpApplicationName,
			lpCommandLine,
			lpProcessAttributes,
			lpThreadAttributes,
			bInheritHandles,
			dwCreationFlags | CREATE_SUSPENDED,
			lpEnvironment,
			lpCurrentDirectory,
			lpStartupInfo,
			lpProcessInformation,
			thisModuleFileName
		);

	if(retV == TRUE)
	{
		if(!isSuspended)
		{
			ResumeThread(lpProcessInformation->hThread);
		};
	};

	return retV;
};
