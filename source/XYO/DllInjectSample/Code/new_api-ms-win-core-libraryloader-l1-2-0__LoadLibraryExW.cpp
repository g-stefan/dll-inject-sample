static HINSTANCE WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW(const wchar_t *lpLibFileName, HANDLE hFile, DWORD dwFlags) {
	HINSTANCE retV;

	// OutputDebugStringXW(L"core.LoadLibraryExW:",lpLibFileName);

	retV = (*_original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW)(lpLibFileName, hFile, dwFlags);
	DWORD errCode = GetLastError();

	if (((dwFlags & DONT_RESOLVE_DLL_REFERENCES) != DONT_RESOLVE_DLL_REFERENCES) &&
	    ((dwFlags & LOAD_LIBRARY_AS_DATAFILE) != LOAD_LIBRARY_AS_DATAFILE)) {
		thisHookInstance(retV);
	};

	SetLastError(errCode);
	return retV;
};
