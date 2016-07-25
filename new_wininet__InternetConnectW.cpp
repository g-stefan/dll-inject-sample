static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectW(HINTERNET hInternet,WCHAR * lpszServerName,INTERNET_PORT nServerPort,WCHAR * lpszUsername,WCHAR * lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext){
	HINTERNET retV;

	OutputDebugStringA("wininet.InternetConnectW");

	retV=(*_original_wininet__InternetConnectW)(hInternet,lpszServerName,nServerPort,lpszUsername,lpszPassword,dwService,dwFlags,dwContext);
	return retV;
};
