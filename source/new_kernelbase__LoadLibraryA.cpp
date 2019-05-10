static HMODULE WINAPI _new_kernelbase__LoadLibraryA(const char *lpFileName)
{
	HMODULE retV;
	retV = (*_original_kernelbase__LoadLibraryA)(lpFileName);
	DWORD errCode = GetLastError();

	thisHookInstance(retV);

	SetLastError(errCode);
	return retV;
};
