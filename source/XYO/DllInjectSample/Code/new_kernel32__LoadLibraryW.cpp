static HMODULE WINAPI _new_kernel32__LoadLibraryW(const wchar_t *lpFileName) {
	HMODULE retV;
	retV = (*_original_kernel32__LoadLibraryW)(lpFileName);
	DWORD errCode = GetLastError();

	thisHookInstance(retV);

	SetLastError(errCode);
	return retV;
};
