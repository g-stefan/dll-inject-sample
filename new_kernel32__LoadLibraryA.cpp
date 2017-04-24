static HMODULE WINAPI _new_kernel32__LoadLibraryA(const char *lpFileName) {
	HMODULE retV;
	retV=(*_original_kernel32__LoadLibraryA)(lpFileName);
	DWORD errCode=GetLastError();

	thisHookInstance(retV);

	SetLastError(errCode);
	return retV;
};
