static int WSAAPI _new_ws2_32__send_19(SOCKET s,const char *buf,int len,int flags) {
	int retV;

	OutputDebugStringA("_new_ws2_32__send_19");

	retV=(*_original_ws2_32__send_19)(s,buf,len,flags);
	return retV;
};
