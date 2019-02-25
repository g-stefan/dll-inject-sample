//
// Dll Inject Sample
//
// Copyright (c) 2018-2019 Grigore Stefan <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#include "dll-inject-sample-license.hpp"

namespace DllInjectSample {
	namespace License {

		static const char *license_ =
			"\r\n"
			"MIT License (MIT)\r\n"
			"\r\n"
			"Copyright (c) 2018-2019 Grigore Stefan <g_stefan@yahoo.com>\r\n"
			"\r\n"
			"Permission is hereby granted, free of charge, to any person obtaining a copy of\r\n"
			"this software and associated documentation files (the \"Software\"), to deal in\r\n"
			"the Software without restriction, including without limitation the rights to\r\n"
			"use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of\r\n"
			"the Software, and to permit persons to whom the Software is furnished to do so,\r\n"
			"subject to the following conditions:\r\n"
			"\r\n"
			"The above copyright notice and this permission notice shall be included in all\r\n"
			"copies or substantial portions of the Software.\r\n"
			"\r\n"
			"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\r\n"
			"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS\r\n"
			"FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR\r\n"
			"COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER\r\n"
			"IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN\r\n"
			"CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\r\n"
			"\r\n";

		static const char *shortLicense_ =
			"\r\n"
			"Copyright (c) 2018-2019 Grigore Stefan <g_stefan@yahoo.com>\r\n"
			"MIT License (MIT) <http://opensource.org/licenses/MIT>\r\n"
			"\r\n";

		const char *content() {
			return license_;
		};

		const char *shortContent() {
			return shortLicense_;
		};

	};
};

