static FARPROC WINAPI _new_kernelbase__GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{

	//OutputDebugStringZA("kernelbase.GetProcAddress:",hModule,lpProcName);

	return hook_GetProcAddress((FARPROC)_original_kernelbase__GetProcAddress, hModule, lpProcName);
};
