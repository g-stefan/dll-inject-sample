//
// Dll Inject Sample
//
// Copyright (c) 2020-2022 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#include "dll-inject-sample-copyright.hpp"

namespace DllInjectSample {
	namespace Copyright {

		static const char *copyright_ = "Copyright (c) Grigore Stefan";
		static const char *publisher_ = "Grigore Stefan";
		static const char *company_ = "Grigore Stefan";
		static const char *contact_ = "g_stefan@yahoo.com";
		static const char *fullCopyright_ = "Copyright (c) Grigore Stefan <g_stefan@yahoo.com>";

		const char *copyright() {
			return copyright_;
		};

		const char *publisher() {
			return publisher_;
		};

		const char *company() {
			return company_;
		};

		const char *contact() {
			return contact_;
		};

		const char *fullCopyright() {
			return fullCopyright_;
		};

	};
};

