static int WSAAPI _new_wsock32__recv(SOCKET s, char *buf, int len, int flags)
{
	int retV;

//	OutputDebugStringA("wsock32.recv");

	retV = (*_original_wsock32__recv)(s, buf, len, flags);
	DWORD errCode = GetLastError();

	if(retV > 0)
	{
		recvHookProcess(getHookProcess(), buf, retV);
	};

	SetLastError(errCode);
	return retV;
};
