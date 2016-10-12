static int WSAAPI _new_ws2_32__connect(SOCKET s,const struct sockaddr *addr,int sz){
	int retV;

//	OutputDebugStringA("ws2_32.connect");

	retV=(*_original_ws2_32__connect)(s,addr,sz);
	return retV;
};
