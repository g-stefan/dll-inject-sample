static int WSAAPI _new_wsock32__connect(SOCKET s, const struct sockaddr *addr, int sz){
	int retV;

//	OutputDebugStringA("wsock32.connect");

	retV=(*_original_wsock32__connect)(s,addr,sz);
	return retV;
};
