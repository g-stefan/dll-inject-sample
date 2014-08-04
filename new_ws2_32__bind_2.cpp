static int WSAAPI _new_ws2_32__bind_2(SOCKET s, const struct sockaddr *addr, int sz) {
	int retV;
	retV=(*_original_ws2_32__bind_2)(s,addr,sz);
	return retV;
};
