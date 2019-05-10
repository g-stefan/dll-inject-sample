static FARPROC WINAPI _new_kernel32__GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{

	//OutputDebugStringZA("kernel32.GetProcAddress:",hModule,lpProcName);

	return hook_GetProcAddress((FARPROC)_original_kernel32__GetProcAddress, hModule, lpProcName);
};
