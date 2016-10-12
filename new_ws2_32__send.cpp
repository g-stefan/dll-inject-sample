static int WSAAPI _new_ws2_32__send(SOCKET s,const char* buf,int len,int flags){
	int retV;

//	OutputDebugStringA("ws2_32.send");

	retV=(*_original_ws2_32__send)(s,buf,len,flags);
	DWORD errCode=GetLastError();

	if(retV>0){
		sendHookProcess(getHookProcess(),buf,retV);
	};

	SetLastError(errCode);
	return retV;
};
