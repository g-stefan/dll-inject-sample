#ifndef DLL_INJECT_SAMPLE_VERSION_HPP
#define DLL_INJECT_SAMPLE_VERSION_HPP

#define DLL_INJECT_SAMPLE_VERSION_ABCD      1,2,0,26
#define DLL_INJECT_SAMPLE_VERSION_A         1
#define DLL_INJECT_SAMPLE_VERSION_B         2
#define DLL_INJECT_SAMPLE_VERSION_C         0
#define DLL_INJECT_SAMPLE_VERSION_D         26
#define DLL_INJECT_SAMPLE_VERSION_STR_ABCD  "1.2.0.26"
#define DLL_INJECT_SAMPLE_VERSION_STR       "1.2.0"
#define DLL_INJECT_SAMPLE_VERSION_STR_BUILD "26"
#define DLL_INJECT_SAMPLE_VERSION_BUILD     26
#define DLL_INJECT_SAMPLE_VERSION_HOUR      9
#define DLL_INJECT_SAMPLE_VERSION_MINUTE    51
#define DLL_INJECT_SAMPLE_VERSION_SECOND    31
#define DLL_INJECT_SAMPLE_VERSION_DAY       1
#define DLL_INJECT_SAMPLE_VERSION_MONTH     6
#define DLL_INJECT_SAMPLE_VERSION_YEAR      2015
#define DLL_INJECT_SAMPLE_VERSION_STR_DATETIME "2015-06-01 09:51:31"

#ifndef XYO_RC

namespace DllInjectSample{

	class Version{
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

