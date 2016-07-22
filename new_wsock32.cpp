typedef int (WSAAPI *_ptr_wsock32__connect_4)(SOCKET s, const struct sockaddr *addr, int sz);
static _ptr_wsock32__connect_4 _original_wsock32__connect_4;
static int WSAAPI _new_wsock32__connect_4(SOCKET s, const struct sockaddr *addr, int sz);
static void _replace_wsock32__connect_4(HINSTANCE hInstance,BOOL mode) {
	_ptr_wsock32__connect_4 _function;
	if(hInstance!=GetModuleHandle("wsock32.dll")) {
		_function=(_ptr_wsock32__connect_4)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__connect_4,"wsock32.dll","connect",4,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_wsock32__connect_4)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__connect_4,"wsock32","connect",4,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_wsock32__connect_4=_function;
		};
	};
};
typedef int (WSAAPI *_ptr_wsock32__recv_16)(SOCKET s, char *buf,int len,int flags);
static _ptr_wsock32__recv_16 _original_wsock32__recv_16;
static int WSAAPI _new_wsock32__recv_16(SOCKET s, char *buf,int len,int flags);
static void _replace_wsock32__recv_16(HINSTANCE hInstance,BOOL mode) {
	_ptr_wsock32__recv_16 _function;
	if(hInstance!=GetModuleHandle("wsock32.dll")) {
		_function=(_ptr_wsock32__recv_16)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__recv_16,"wsock32.dll","recv",16,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_wsock32__recv_16)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__recv_16,"wsock32","recv",16,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_wsock32__recv_16=_function;
		};
	};
};
typedef int (WSAAPI *_ptr_wsock32__send_19)(SOCKET s,const char *buf,int len,int flags);
static _ptr_wsock32__send_19 _original_wsock32__send_19;
static int WSAAPI _new_wsock32__send_19(SOCKET s,const char *buf,int len,int flags);
static void _replace_wsock32__send_19(HINSTANCE hInstance,BOOL mode) {
	_ptr_wsock32__send_19 _function;
	if(hInstance!=GetModuleHandle("wsock32.dll")) {
		_function=(_ptr_wsock32__send_19)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__send_19,"wsock32.dll","send",19,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_wsock32__send_19)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__send_19,"wsock32","send",19,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_wsock32__send_19=_function;
		};
	};
};
typedef int (WSAAPI *_ptr_wsock32__bind_2)(SOCKET s, const struct sockaddr *addr, int sz);
static _ptr_wsock32__bind_2 _original_wsock32__bind_2;
static int WSAAPI _new_wsock32__bind_2(SOCKET s, const struct sockaddr *addr, int sz);
static void _replace_wsock32__bind_2(HINSTANCE hInstance,BOOL mode) {
	_ptr_wsock32__bind_2 _function;
	if(hInstance!=GetModuleHandle("wsock32.dll")) {
		_function=(_ptr_wsock32__bind_2)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__bind_2,"wsock32.dll","bind",2,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_wsock32__bind_2)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wsock32__bind_2,"wsock32","bind",2,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_wsock32__bind_2=_function;
		};
	};
};
