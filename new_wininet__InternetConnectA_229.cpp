static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectA_229(HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext) {
	HINTERNET retV;

	OutputDebugStringA("_new_wininet__InternetConnectA_229");

	retV=(*_original_wininet__InternetConnectA_229)(hInternet,lpszServerName,nServerPort,lpszUsername,lpszPassword,dwService,dwFlags,dwContext);
	return retV;
};
