static int WSAAPI _new_ws2_32__WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
	int retV;

//	OutputDebugStringA("ws2_32.WSARecv");

	retV=_original_ws2_32__WSARecv(s,lpBuffers,dwBufferCount,lpNumberOfBytesRecvd,lpFlags,lpOverlapped,lpCompletionRoutine);
	DWORD errCode=GetLastError();

	HookProcess *hookProcess=getHookProcess();

	hookProcess->WSARecv_lpBuffers=lpBuffers;
	hookProcess->WSARecv_dwBufferCount=dwBufferCount;
	hookProcess->WSARecv_lpOverlapped=lpOverlapped;

	SetLastError(errCode);
	return retV;
};
