static int WSAAPI _new_wsock32__recv_16(SOCKET s, char *buf,int len,int flags) {
	int retV;

	OutputDebugStringA("_new_wsock32__recv_16");

	retV=(*_original_wsock32__recv_16)(s,buf,len,flags);
	return retV;
};
