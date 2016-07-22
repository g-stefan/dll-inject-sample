static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectW_230(HINTERNET hInternet,WCHAR *lpszServerName,INTERNET_PORT nServerPort,WCHAR *lpszUsername,WCHAR *lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext) {
	HINTERNET retV;

	OutputDebugStringA("_new_wininet__InternetConnectW_230");

	retV=(*_original_wininet__InternetConnectW_230)(hInternet,lpszServerName,nServerPort,lpszUsername,lpszPassword,dwService,dwFlags,dwContext);
	return retV;
};
