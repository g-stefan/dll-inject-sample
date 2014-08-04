//
// Dll Inject Sample
//
// Copyright (c) 2014 Grigore Stefan, <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// The MIT License (MIT) <http://opensource.org/licenses/MIT>
//

.solution("dll-inject-sample",function() {

	.project("dll-inject-sample","dll",function() {

		.file("source",["dll-inject-sample*.cpp","dll-inject-sample*.hpp","dll-inject-sample*.rc"]);

		.option("version","xyo-version", {
			type:"xyo-cpp",
			sourceBegin:"namespace DllInjectSample{\r\n",
			sourceEnd:"\r\n};\r\n",
			lineBegin:"\t"
		});

		.option("sign","xyo-security");
		.option("licence","mit");
		.dependency("libxyo-win-inject","libxyo-win-inject","lib");
	});

});

