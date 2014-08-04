#ifndef DLL_INJECT_SAMPLE_VERSION_HPP
#define DLL_INJECT_SAMPLE_VERSION_HPP

#define DLL_INJECT_SAMPLE_VERSION_ABCD      1,2,0,22
#define DLL_INJECT_SAMPLE_VERSION_A         1
#define DLL_INJECT_SAMPLE_VERSION_B         2
#define DLL_INJECT_SAMPLE_VERSION_C         0
#define DLL_INJECT_SAMPLE_VERSION_D         22
#define DLL_INJECT_SAMPLE_VERSION_STR_ABCD  "1.2.0.22"
#define DLL_INJECT_SAMPLE_VERSION_STR       "1.2.0"
#define DLL_INJECT_SAMPLE_VERSION_STR_BUILD "22"
#define DLL_INJECT_SAMPLE_VERSION_BUILD     22
#define DLL_INJECT_SAMPLE_VERSION_HOUR      13
#define DLL_INJECT_SAMPLE_VERSION_MINUTE    23
#define DLL_INJECT_SAMPLE_VERSION_SECOND    38
#define DLL_INJECT_SAMPLE_VERSION_DAY       3
#define DLL_INJECT_SAMPLE_VERSION_MONTH     7
#define DLL_INJECT_SAMPLE_VERSION_YEAR      2014
#define DLL_INJECT_SAMPLE_VERSION_STR_DATETIME "2014-07-03 13:23:38"

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

