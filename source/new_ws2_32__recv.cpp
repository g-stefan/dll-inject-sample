static int WSAAPI _new_ws2_32__recv(SOCKET s, char *buf, int len, int flags) {
	int retV;

//	OutputDebugStringA("ws2_32.recv");

	retV = (*_original_ws2_32__recv)(s, buf, len, flags);
	DWORD errCode = GetLastError();

	if(retV > 0) {
		recvHookProcess(getHookProcess(), buf, retV);
	};

	SetLastError(errCode);
	return retV;
};
