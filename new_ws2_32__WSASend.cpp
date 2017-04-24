static int WSAAPI _new_ws2_32__WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesSent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
	int retV;

//	OutputDebugStringA("ws2_32.WSASend");

	retV=_original_ws2_32__WSASend(s,lpBuffers,dwBufferCount,lpNumberOfBytesSent,dwFlags,lpOverlapped,lpCompletionRoutine);
	DWORD errCode=GetLastError();

	HookProcess *hookProcess=getHookProcess();

	hookProcess->WSASend_lpBuffers=lpBuffers;
	hookProcess->WSASend_dwBufferCount=dwBufferCount;
	hookProcess->WSASend_lpOverlapped=lpOverlapped;

	SetLastError(errCode);
	return retV;
};
