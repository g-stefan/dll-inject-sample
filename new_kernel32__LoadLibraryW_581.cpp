static HMODULE WINAPI _new_kernel32__LoadLibraryW_581(const wchar_t *lpFileName) {
	HMODULE retV;
	retV=(*_original_kernel32__LoadLibraryW_581)(lpFileName);

	thisHookInstance(retV);

	return retV;
};
