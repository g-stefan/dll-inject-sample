static FARPROC WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{

	//OutputDebugStringZA("core.GetProcAddress:",hModule,lpProcName);

	return hook_GetProcAddress((FARPROC)_original_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress, hModule, lpProcName);
};
