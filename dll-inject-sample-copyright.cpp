//
// Dll Inject Sample
//
// Copyright (c) 2018-2019 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#include "dll-inject-sample-copyright.hpp"

namespace DllInjectSample {

	static const char *copyright_ = "Copyright (c) Grigore Stefan";
	static const char *publisher_ = "Grigore Stefan";
	static const char *company_ = "Grigore Stefan";
	static const char *contact_ = "g_stefan@yahoo.com";
	static const char *fullCopyright_ = "Copyright (c) Grigore Stefan <g_stefan@yahoo.com>";

	const char *Copyright::copyright() {
		return copyright_;
	};

	const char *Copyright::publisher() {
		return publisher_;
	};

	const char *Copyright::company() {
		return company_;
	};

	const char *Copyright::contact() {
		return contact_;
	};

	const char *Copyright::fullCopyright() {
		return fullCopyright_;
	};

};

