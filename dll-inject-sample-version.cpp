//
// Dll Inject Sample
//
// Copyright (c) 2018-2019 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#include "dll-inject-sample-version.hpp"

namespace DllInjectSample {

	static const char *versionVersion="1.0.0";
	static const char *versionBuild="33";
	static const char *versionVersionWithBuild="1.0.0.33";
	static const char *versionDatetime="2018-04-16 13:04:23";

	const char *Version::getVersion() {
		return versionVersion;
	};
	const char *Version::getBuild() {
		return versionBuild;
	};
	const char *Version::getVersionWithBuild() {
		return versionVersionWithBuild;
	};
	const char *Version::getDatetime() {
		return versionDatetime;
	};

};

