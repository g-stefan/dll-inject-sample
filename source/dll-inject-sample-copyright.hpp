//
// Dll Inject Sample
//
// Copyright (c) 2020-2022 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef DLL_INJECT_SAMPLE_COPYRIGHT_HPP
#define DLL_INJECT_SAMPLE_COPYRIGHT_HPP

#define DLL_INJECT_SAMPLE_COPYRIGHT "Copyright (c) Grigore Stefan"
#define DLL_INJECT_SAMPLE_PUBLISHER "Grigore Stefan"
#define DLL_INJECT_SAMPLE_COMPANY DLL_INJECT_SAMPLE_PUBLISHER
#define DLL_INJECT_SAMPLE_CONTACT "g_stefan@yahoo.com"
#define DLL_INJECT_SAMPLE_FULL_COPYRIGHT DLL_INJECT_SAMPLE_COPYRIGHT " <" DLL_INJECT_SAMPLE_CONTACT ">"

#ifndef XYO_RC

namespace DllInjectSample {
	namespace Copyright {
		const char *copyright();
		const char *publisher();
		const char *company();
		const char *contact();
		const char *fullCopyright();
	};
};

#endif
#endif
