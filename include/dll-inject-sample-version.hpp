//
// Dll Inject Sample
//
// Copyright (c) 2018-2019 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef DLL_INJECT_SAMPLE_VERSION_HPP
#define DLL_INJECT_SAMPLE_VERSION_HPP

#define DLL_INJECT_SAMPLE_VERSION_ABCD                1,0,0,39
#define DLL_INJECT_SAMPLE_VERSION_STR                 "1.0.0"
#define DLL_INJECT_SAMPLE_VERSION_STR_BUILD           "39"
#define DLL_INJECT_SAMPLE_VERSION_STR_DATETIME        "2019-05-13 02:59:52"

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

