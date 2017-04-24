typedef int (WSAAPI *_ptr_wsock32__connect)(SOCKET s, const struct sockaddr *addr, int sz);
static int WSAAPI _new_wsock32__connect(SOCKET s, const struct sockaddr *addr, int sz);
static XYO::Win::Inject::Hook::HookProc _hook_wsock32__connect;
#define _original_wsock32__connect ((_ptr_wsock32__connect)(_hook_wsock32__connect.originalProc))
typedef int (WSAAPI *_ptr_wsock32__recv)(SOCKET s, char *buf,int len,int flags);
static int WSAAPI _new_wsock32__recv(SOCKET s, char *buf,int len,int flags);
static XYO::Win::Inject::Hook::HookProc _hook_wsock32__recv;
#define _original_wsock32__recv ((_ptr_wsock32__recv)(_hook_wsock32__recv.originalProc))
typedef int (WSAAPI *_ptr_wsock32__send)(SOCKET s,const char *buf,int len,int flags);
static int WSAAPI _new_wsock32__send(SOCKET s,const char *buf,int len,int flags);
static XYO::Win::Inject::Hook::HookProc _hook_wsock32__send;
#define _original_wsock32__send ((_ptr_wsock32__send)(_hook_wsock32__send.originalProc))
typedef int (WSAAPI *_ptr_wsock32__bind)(SOCKET s, const struct sockaddr *addr, int sz);
static int WSAAPI _new_wsock32__bind(SOCKET s, const struct sockaddr *addr, int sz);
static XYO::Win::Inject::Hook::HookProc _hook_wsock32__bind;
#define _original_wsock32__bind ((_ptr_wsock32__bind)(_hook_wsock32__bind.originalProc))
