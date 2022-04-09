static int WSAAPI _new_wsock32__send(SOCKET s, const char *buf, int len, int flags) {
	int retV;

	//	OutputDebugStringA("wsock32.send");

	retV = (*_original_wsock32__send)(s, buf, len, flags);
	DWORD errCode = GetLastError();

	if (retV > 0) {
		sendHookProcess(getHookProcess(), buf, retV);
	};

	SetLastError(errCode);
	return retV;
};
