static int WSAAPI _new_ws2_32__bind(SOCKET s, const struct sockaddr *addr, int sz){
	int retV;

//	OutputDebugStringA("ws2_32.bind");

	retV=(*_original_ws2_32__bind)(s,addr,sz);
	return retV;
};
