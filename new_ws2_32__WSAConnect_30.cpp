static int WSAAPI _new_ws2_32__WSAConnect_30(SOCKET s,const struct sockaddr *name,int namelen,void *lpCallerData,void *lpCalleeData,void *lpSQOS,void *lpGQOS) {
	int retV;

	OutputDebugStringA("_new_ws2_32__WSAConnect_30");

	retV=(*_original_ws2_32__WSAConnect_30)(s,name,namelen,lpCallerData,lpCalleeData,lpSQOS,lpGQOS);
	return retV;
};
