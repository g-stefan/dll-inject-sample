static int WSAAPI _new_wsock32__connect_4(SOCKET s, const struct sockaddr *addr, int sz) {
	int retV;

	OutputDebugStringA("_new_wsock32__connect_4");

	retV=(*_original_wsock32__connect_4)(s,addr,sz);
	return retV;
};
