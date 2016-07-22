static FARPROC WINAPI _new_kernelbase__GetProcAddress_598(HMODULE hModule,LPCSTR lpProcName) {
	FARPROC retV;

	//OutputDebugStringZA("kernelbase-get-proc-address:",hModule,lpProcName);

	retV=(*_original_kernelbase__GetProcAddress_598)(hModule,lpProcName);

	return hook_GetProcAddress(retV,hModule,lpProcName);
};
