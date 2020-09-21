//
// Dll Inject Sample
//
// Copyright (c) 2020 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#include "dll-inject-sample-version.hpp"

namespace DllInjectSample {
	namespace Version {

		static const char *version_ = "1.1.0";
		static const char *build_ = "3";
		static const char *versionWithBuild_ = "1.1.0.3";
		static const char *datetime_ = "2020-09-21 17:40:13";

		const char *version() {
			return version_;
		};
		const char *build() {
			return build_;
		};
		const char *versionWithBuild() {
			return versionWithBuild_;
		};
		const char *datetime() {
			return datetime_;
		};

	};
};

