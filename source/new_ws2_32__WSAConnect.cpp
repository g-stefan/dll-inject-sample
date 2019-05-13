static int WSAAPI _new_ws2_32__WSAConnect(SOCKET s, const struct sockaddr *name, int namelen, void *lpCallerData, void *lpCalleeData, void *lpSQOS, void *lpGQOS) {
	int retV;

//	OutputDebugStringA("ws2_32.WSAConnect");

	retV = (*_original_ws2_32__WSAConnect)(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS);
	return retV;
};
