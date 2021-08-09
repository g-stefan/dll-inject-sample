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

#define DLL_INJECT_SAMPLE_VERSION_ABCD                1,5,0,10
#define DLL_INJECT_SAMPLE_VERSION_STR                 "1.5.0"
#define DLL_INJECT_SAMPLE_VERSION_STR_BUILD           "10"
#define DLL_INJECT_SAMPLE_VERSION_STR_DATETIME        "2021-08-05 20:38:20"

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

