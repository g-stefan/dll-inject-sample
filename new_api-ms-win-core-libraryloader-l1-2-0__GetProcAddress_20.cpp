static FARPROC WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20(HMODULE hModule,LPCSTR lpProcName) {
	FARPROC retV;

	//OutputDebugStringZA("core_GetProcAddress:",hModule,lpProcName);

	retV=(*_original_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20)(hModule,lpProcName);

	return hook_GetProcAddress(retV,hModule,lpProcName);
};
