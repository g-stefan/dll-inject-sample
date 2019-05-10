typedef int (WSAAPI *_ptr_ws2_32__connect)(SOCKET s, const struct sockaddr *addr, int sz);
static int WSAAPI _new_ws2_32__connect(SOCKET s, const struct sockaddr *addr, int sz);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__connect;
#define _original_ws2_32__connect ((_ptr_ws2_32__connect)(_hook_ws2_32__connect.originalProc))
typedef int (WSAAPI *_ptr_ws2_32__recv)(SOCKET s, char *buf, int len, int flags);
static int WSAAPI _new_ws2_32__recv(SOCKET s, char *buf, int len, int flags);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__recv;
#define _original_ws2_32__recv ((_ptr_ws2_32__recv)(_hook_ws2_32__recv.originalProc))
typedef int (WSAAPI *_ptr_ws2_32__WSAConnect)(SOCKET s, const struct sockaddr *name, int namelen, void *lpCallerData, void *lpCalleeData, void *lpSQOS, void *lpGQOS);
static int WSAAPI _new_ws2_32__WSAConnect(SOCKET s, const struct sockaddr *name, int namelen, void *lpCallerData, void *lpCalleeData, void *lpSQOS, void *lpGQOS);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__WSAConnect;
#define _original_ws2_32__WSAConnect ((_ptr_ws2_32__WSAConnect)(_hook_ws2_32__WSAConnect.originalProc))
typedef int (WSAAPI *_ptr_ws2_32__send)(SOCKET s, const char *buf, int len, int flags);
static int WSAAPI _new_ws2_32__send(SOCKET s, const char *buf, int len, int flags);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__send;
#define _original_ws2_32__send ((_ptr_ws2_32__send)(_hook_ws2_32__send.originalProc))
typedef int (WSAAPI *_ptr_ws2_32__bind)(SOCKET s, const struct sockaddr *addr, int sz);
static int WSAAPI _new_ws2_32__bind(SOCKET s, const struct sockaddr *addr, int sz);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__bind;
#define _original_ws2_32__bind ((_ptr_ws2_32__bind)(_hook_ws2_32__bind.originalProc))
typedef int (WSAAPI *_ptr_ws2_32__WSARecv)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
static int WSAAPI _new_ws2_32__WSARecv(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__WSARecv;
#define _original_ws2_32__WSARecv ((_ptr_ws2_32__WSARecv)(_hook_ws2_32__WSARecv.originalProc))
typedef int (WSAAPI *_ptr_ws2_32__WSASend)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
static int WSAAPI _new_ws2_32__WSASend(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__WSASend;
#define _original_ws2_32__WSASend ((_ptr_ws2_32__WSASend)(_hook_ws2_32__WSASend.originalProc))
typedef BOOL (WSAAPI *_ptr_ws2_32__WSAGetOverlappedResult)(SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPDWORD lpcbTransfer, BOOL fWait, LPDWORD lpdwFlags);
static BOOL WSAAPI _new_ws2_32__WSAGetOverlappedResult(SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPDWORD lpcbTransfer, BOOL fWait, LPDWORD lpdwFlags);
static XYO::Win::Inject::Hook::HookProc _hook_ws2_32__WSAGetOverlappedResult;
#define _original_ws2_32__WSAGetOverlappedResult ((_ptr_ws2_32__WSAGetOverlappedResult)(_hook_ws2_32__WSAGetOverlappedResult.originalProc))
