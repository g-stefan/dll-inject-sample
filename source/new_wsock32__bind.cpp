static int WSAAPI _new_wsock32__bind(SOCKET s, const struct sockaddr *addr, int sz) {
	int retV;

//	OutputDebugStringA("wsock32.bind");

	retV = (*_original_wsock32__bind)(s, addr, sz);
	return retV;
};
