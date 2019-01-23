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

#define DLL_INJECT_SAMPLE_VERSION_ABCD                1,0,0,33
#define DLL_INJECT_SAMPLE_VERSION_STR                 "1.0.0"
#define DLL_INJECT_SAMPLE_VERSION_STR_BUILD           "33"
#define DLL_INJECT_SAMPLE_VERSION_STR_DATETIME        "2018-04-16 13:04:23"

#ifndef XYO_RC

namespace DllInjectSample {

	class Version {
		public:
			static const char *getVersion();
			static const char *getBuild();
			static const char *getVersionWithBuild();
			static const char *getDatetime();
	};

};

#endif
#endif

