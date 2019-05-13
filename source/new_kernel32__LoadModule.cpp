typedef struct tagLOADPARMS32 {
	LPSTR lpEnvAddress;  // address of environment strings
	LPSTR lpCmdLine;     // address of command line
	LPSTR lpCmdShow;     // how to show new program
	DWORD dwReserved;    // must be zero
} LOADPARMS32;

static DWORD WINAPI _new_kernel32__LoadModule(LPCSTR lpModuleName, LPVOID lpParameterBlock) {
	DWORD retV;
	STARTUPINFO         sInfo;
	PROCESS_INFORMATION pInfo;
	BOOL    isOk;

	memset(&sInfo, 0, sizeof(sInfo));
	memset(&pInfo, 0, sizeof(pInfo));
	sInfo.cb = sizeof(sInfo);
	sInfo.wShowWindow = ((WORD *)((LOADPARMS32 *)lpParameterBlock)->lpCmdShow)[1];

	isOk = XYO::Win::Inject::Process::createProcessA(
			lpModuleName,
			((LOADPARMS32 *)lpParameterBlock)->lpCmdLine,
			NULL,
			NULL,
			FALSE,
			CREATE_SUSPENDED,
			((LOADPARMS32 *)lpParameterBlock)->lpEnvAddress,
			NULL,
			&sInfo,
			&pInfo,
			thisModuleFileName
		);

	if(isOk) {
		ResumeThread(pInfo.hThread);
		CloseHandle(pInfo.hThread);
		CloseHandle(pInfo.hProcess);
		retV = pInfo.dwProcessId;
	} else {
		retV = 0;
	};

	return retV;
};

