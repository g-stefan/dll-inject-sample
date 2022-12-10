XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__connect, "ws2_32", "connect", (FARPROC)_new_ws2_32__connect);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__recv, "ws2_32", "recv", (FARPROC)_new_ws2_32__recv);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__WSAConnect, "ws2_32", "WSAConnect", (FARPROC)_new_ws2_32__WSAConnect);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__send, "ws2_32", "send", (FARPROC)_new_ws2_32__send);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__bind, "ws2_32", "bind", (FARPROC)_new_ws2_32__bind);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__WSARecv, "ws2_32", "WSARecv", (FARPROC)_new_ws2_32__WSARecv);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__WSASend, "ws2_32", "WSASend", (FARPROC)_new_ws2_32__WSASend);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_ws2_32__WSAGetOverlappedResult, "ws2_32", "WSAGetOverlappedResult", (FARPROC)_new_ws2_32__WSAGetOverlappedResult);
