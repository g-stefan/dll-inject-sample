XYO::Win::Inject::Hook::setOriginalFunction(_hook_wsock32__connect, "wsock32", "connect", (FARPROC)_new_wsock32__connect);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_wsock32__recv, "wsock32", "recv", (FARPROC)_new_wsock32__recv);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_wsock32__send, "wsock32", "send", (FARPROC)_new_wsock32__send);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_wsock32__bind, "wsock32", "bind", (FARPROC)_new_wsock32__bind);
