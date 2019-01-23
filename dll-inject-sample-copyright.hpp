//
// Dll Inject Sample
//
// Copyright (c) 2018-2019 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#ifndef DLL_INJECT_SAMPLE_COPYRIGHT_HPP
#define DLL_INJECT_SAMPLE_COPYRIGHT_HPP

#define DLL_INJECT_SAMPLE_COPYRIGHT            "Copyright (c) Grigore Stefan"
#define DLL_INJECT_SAMPLE_PUBLISHER            "Grigore Stefan"
#define DLL_INJECT_SAMPLE_COMPANY              DLL_INJECT_SAMPLE_PUBLISHER
#define DLL_INJECT_SAMPLE_CONTACT              "g_stefan@yahoo.com"
#define DLL_INJECT_SAMPLE_FULL_COPYRIGHT       DLL_INJECT_SAMPLE_COPYRIGHT " <" DLL_INJECT_SAMPLE_CONTACT ">"

#ifndef XYO_RC

namespace DllInjectSample {

	class Copyright {
		public:
			static const char *copyright();
			static const char *publisher();
			static const char *company();
			static const char *contact();
			static const char *fullCopyright();

	};

};

#endif
#endif
