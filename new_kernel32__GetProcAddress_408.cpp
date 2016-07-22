static FARPROC WINAPI _new_kernel32__GetProcAddress_408(HMODULE hModule,LPCSTR lpProcName) {
	FARPROC retV=NULL;

	//OutputDebugStringZA("kernel32_GetProcAddress:",hModule,lpProcName);

	retV=(*_original_kernel32__GetProcAddress_408)(hModule,lpProcName);

	return hook_GetProcAddress(retV,hModule,lpProcName);
};
