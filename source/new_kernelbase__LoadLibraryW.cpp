static HMODULE WINAPI _new_kernelbase__LoadLibraryW(const wchar_t *lpFileName)
{
	HMODULE retV;
	retV = (*_original_kernelbase__LoadLibraryW)(lpFileName);
	DWORD errCode = GetLastError();

	thisHookInstance(retV);

	SetLastError(errCode);
	return retV;
};
