//
// Dll Inject Sample
//
// Copyright (c) 2020-2021 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef DLL_INJECT_SAMPLE_VERSION_HPP
#define DLL_INJECT_SAMPLE_VERSION_HPP

#define DLL_INJECT_SAMPLE_VERSION_ABCD                1,7,0,20
#define DLL_INJECT_SAMPLE_VERSION_STR                 "1.7.0"
#define DLL_INJECT_SAMPLE_VERSION_STR_BUILD           "20"
#define DLL_INJECT_SAMPLE_VERSION_STR_DATETIME        "2021-11-15 16:51:55"

#ifndef XYO_RC

namespace DllInjectSample {
	namespace Version {
		const char *version();
		const char *build();
		const char *versionWithBuild();
		const char *datetime();
	};
};

#endif
#endif

