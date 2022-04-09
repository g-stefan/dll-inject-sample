static BOOL STDAPICALLTYPE _new_wininet__InternetReadFile(HINTERNET hFile, LPVOID lpBuffer, DWORD dwNumberOfBytesToRead, LPDWORD lpdwNumberOfBytesRead) {
	BOOL retV;

	//	OutputDebugStringA("wininet.InternetReadFile");

	retV = (*_original_wininet__InternetReadFile)(hFile, lpBuffer, dwNumberOfBytesToRead, lpdwNumberOfBytesRead);
	DWORD errCode = GetLastError();

	if (retV == TRUE) {
		if (*lpdwNumberOfBytesRead > 0) {
			recvHookProcess(getHookProcess(), (char *)lpBuffer, *lpdwNumberOfBytesRead);
		};
	};

	SetLastError(errCode);
	return retV;
};
