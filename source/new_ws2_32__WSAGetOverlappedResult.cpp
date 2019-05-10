static BOOL WSAAPI _new_ws2_32__WSAGetOverlappedResult(SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPDWORD lpcbTransfer, BOOL fWait, LPDWORD lpdwFlags)
{
	BOOL retV;

//	OutputDebugStringA("ws2_32.WSAGetOverlappedResult");

	retV = _original_ws2_32__WSAGetOverlappedResult(s, lpOverlapped, lpcbTransfer, fWait, lpdwFlags);
	DWORD errCode = GetLastError();

	if(retV == TRUE)
	{

		HookProcess *hookProcess = getHookProcess();

		if(hookProcess->WSARecv_lpOverlapped == lpOverlapped)
		{
			DWORD bytesTransfer = *lpcbTransfer;
			if(bytesTransfer > 0)
			{
				DWORD index;
				LPWSABUF lpBuffersIndex = hookProcess->WSARecv_lpBuffers;
				for(index = 0; index < hookProcess->WSARecv_dwBufferCount; ++index, ++lpBuffersIndex)
				{
					if(lpBuffersIndex->len > 0)
					{
						if(bytesTransfer <= lpBuffersIndex->len)
						{
							recvHookProcess(hookProcess, lpBuffersIndex->buf, bytesTransfer);
							break;
						};
						recvHookProcess(hookProcess, lpBuffersIndex->buf, lpBuffersIndex->len);
						bytesTransfer -= lpBuffersIndex->len;
					};
				};
			};
			SetLastError(errCode);
			return retV;
		};

		if(hookProcess->WSASend_lpOverlapped == lpOverlapped)
		{
			DWORD bytesTransfer = *lpcbTransfer;
			if(bytesTransfer > 0)
			{
				DWORD index;
				LPWSABUF lpBuffersIndex = hookProcess->WSASend_lpBuffers;
				for(index = 0; index < hookProcess->WSASend_dwBufferCount; ++index, ++lpBuffersIndex)
				{
					if(lpBuffersIndex->len > 0)
					{
						if(bytesTransfer <= lpBuffersIndex->len)
						{
							sendHookProcess(hookProcess, lpBuffersIndex->buf, bytesTransfer);
							break;
						};
						sendHookProcess(hookProcess, lpBuffersIndex->buf, lpBuffersIndex->len);
						bytesTransfer -= lpBuffersIndex->len;
					};
				};
			};
			SetLastError(errCode);
			return retV;
		};

	};

	SetLastError(errCode);
	return retV;
};
