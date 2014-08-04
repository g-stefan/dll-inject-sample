typedef int (WSAAPI *_ptr_ws2_32__connect_4)(SOCKET s,const struct sockaddr *addr,int sz);
static _ptr_ws2_32__connect_4 _original_ws2_32__connect_4;
static int WSAAPI _new_ws2_32__connect_4(SOCKET s,const struct sockaddr *addr,int sz);
static void _replace_ws2_32__connect_4(HINSTANCE hInstance) {
	_ptr_ws2_32__connect_4 _function;
	if(hInstance!=GetModuleHandle("ws2_32.dll")) {
		_function=(_ptr_ws2_32__connect_4)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__connect_4,"ws2_32.dll","connect",4);
		if(_function!=NULL) {
			_original_ws2_32__connect_4=_function;
		} else {
			_function=(_ptr_ws2_32__connect_4)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__connect_4,"ws2_32","connect",4);
			if(_function!=NULL) {
				_original_ws2_32__connect_4=_function;
			};
		};
	};
};
typedef int (WSAAPI *_ptr_ws2_32__recv_16)(SOCKET s, char *buf,int len,int flags);
static _ptr_ws2_32__recv_16 _original_ws2_32__recv_16;
static int WSAAPI _new_ws2_32__recv_16(SOCKET s, char *buf,int len,int flags);
static void _replace_ws2_32__recv_16(HINSTANCE hInstance) {
	_ptr_ws2_32__recv_16 _function;
	if(hInstance!=GetModuleHandle("ws2_32.dll")) {
		_function=(_ptr_ws2_32__recv_16)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__recv_16,"ws2_32.dll","recv",16);
		if(_function!=NULL) {
			_original_ws2_32__recv_16=_function;
		} else {
			_function=(_ptr_ws2_32__recv_16)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__recv_16,"ws2_32","recv",16);
			if(_function!=NULL) {
				_original_ws2_32__recv_16=_function;
			};
		};
	};
};
typedef int (WSAAPI *_ptr_ws2_32__WSAConnect_30)(SOCKET s,const struct sockaddr *name,int namelen,void *lpCallerData,void *lpCalleeData,void *lpSQOS,void *lpGQOS);
static _ptr_ws2_32__WSAConnect_30 _original_ws2_32__WSAConnect_30;
static int WSAAPI _new_ws2_32__WSAConnect_30(SOCKET s,const struct sockaddr *name,int namelen,void *lpCallerData,void *lpCalleeData,void *lpSQOS,void *lpGQOS);
static void _replace_ws2_32__WSAConnect_30(HINSTANCE hInstance) {
	_ptr_ws2_32__WSAConnect_30 _function;
	if(hInstance!=GetModuleHandle("ws2_32.dll")) {
		_function=(_ptr_ws2_32__WSAConnect_30)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__WSAConnect_30,"ws2_32.dll","WSAConnect",30);
		if(_function!=NULL) {
			_original_ws2_32__WSAConnect_30=_function;
		} else {
			_function=(_ptr_ws2_32__WSAConnect_30)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__WSAConnect_30,"ws2_32","WSAConnect",30);
			if(_function!=NULL) {
				_original_ws2_32__WSAConnect_30=_function;
			};
		};
	};
};
typedef int (WSAAPI *_ptr_ws2_32__send_19)(SOCKET s,const char *buf,int len,int flags);
static _ptr_ws2_32__send_19 _original_ws2_32__send_19;
static int WSAAPI _new_ws2_32__send_19(SOCKET s,const char *buf,int len,int flags);
static void _replace_ws2_32__send_19(HINSTANCE hInstance) {
	_ptr_ws2_32__send_19 _function;
	if(hInstance!=GetModuleHandle("ws2_32.dll")) {
		_function=(_ptr_ws2_32__send_19)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__send_19,"ws2_32.dll","send",19);
		if(_function!=NULL) {
			_original_ws2_32__send_19=_function;
		} else {
			_function=(_ptr_ws2_32__send_19)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__send_19,"ws2_32","send",19);
			if(_function!=NULL) {
				_original_ws2_32__send_19=_function;
			};
		};
	};
};
typedef int (WSAAPI *_ptr_ws2_32__bind_2)(SOCKET s, const struct sockaddr *addr, int sz);
static _ptr_ws2_32__bind_2 _original_ws2_32__bind_2;
static int WSAAPI _new_ws2_32__bind_2(SOCKET s, const struct sockaddr *addr, int sz);
static void _replace_ws2_32__bind_2(HINSTANCE hInstance) {
	_ptr_ws2_32__bind_2 _function;
	if(hInstance!=GetModuleHandle("ws2_32.dll")) {
		_function=(_ptr_ws2_32__bind_2)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__bind_2,"ws2_32.dll","bind",2);
		if(_function!=NULL) {
			_original_ws2_32__bind_2=_function;
		} else {
			_function=(_ptr_ws2_32__bind_2)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_ws2_32__bind_2,"ws2_32","bind",2);
			if(_function!=NULL) {
				_original_ws2_32__bind_2=_function;
			};
		};
	};
};
