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

	static const char *versionVersion="%VERSION_VERSION%";
	static const char *versionBuild="%VERSION_BUILD%";
	static const char *versionVersionWithBuild="%VERSION_VERSION%.%VERSION_BUILD%";
	static const char *versionDatetime="%VERSION_DATETIME%";

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

