static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectA(HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext){
	HINTERNET retV;

	OutputDebugStringA("wininet.InternetConnectA");

	retV=(*_original_wininet__InternetConnectA)(hInternet,lpszServerName,nServerPort,lpszUsername,lpszPassword,dwService,dwFlags,dwContext);
	return retV;
};
