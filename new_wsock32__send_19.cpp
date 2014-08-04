static int WSAAPI _new_wsock32__send_19(SOCKET s,const char *buf,int len,int flags) {
	int retV;
	retV=(*_original_wsock32__send_19)(s,buf,len,flags);
	return retV;
};
