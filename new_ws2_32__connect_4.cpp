static int WSAAPI _new_ws2_32__connect_4(SOCKET s,const struct sockaddr *addr,int sz) {
	int retV;

	OutputDebugStringA("_new_ws2_32__connect_4");

	retV=(*_original_ws2_32__connect_4)(s,addr,sz);
	return retV;
};
