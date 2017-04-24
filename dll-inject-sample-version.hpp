#ifndef DLL_INJECT_SAMPLE_VERSION_HPP
#define DLL_INJECT_SAMPLE_VERSION_HPP

#define DLL_INJECT_SAMPLE_VERSION_ABCD      2,0,0,32
#define DLL_INJECT_SAMPLE_VERSION_A         2
#define DLL_INJECT_SAMPLE_VERSION_B         0
#define DLL_INJECT_SAMPLE_VERSION_C         0
#define DLL_INJECT_SAMPLE_VERSION_D         32
#define DLL_INJECT_SAMPLE_VERSION_STR_ABCD  "2.0.0.32"
#define DLL_INJECT_SAMPLE_VERSION_STR       "2.0.0"
#define DLL_INJECT_SAMPLE_VERSION_STR_BUILD "32"
#define DLL_INJECT_SAMPLE_VERSION_BUILD     32
#define DLL_INJECT_SAMPLE_VERSION_HOUR      0
#define DLL_INJECT_SAMPLE_VERSION_MINUTE    16
#define DLL_INJECT_SAMPLE_VERSION_SECOND    56
#define DLL_INJECT_SAMPLE_VERSION_DAY       25
#define DLL_INJECT_SAMPLE_VERSION_MONTH     4
#define DLL_INJECT_SAMPLE_VERSION_YEAR      2017
#define DLL_INJECT_SAMPLE_VERSION_STR_DATETIME "2017-04-25 00:16:56"

#ifndef XYO_RC

namespace DllInjectSample {

	class Version {
		public:
			static const char *getABCD();
			static const char *getA();
			static const char *getB();
			static const char *getC();
			static const char *getD();
			static const char *getVersion();
			static const char *getBuild();
			static const char *getHour();
			static const char *getMinute();
			static const char *getSecond();
			static const char *getDay();
			static const char *getMonth();
			static const char *getYear();
			static const char *getDatetime();
	};


};

#endif
#endif

