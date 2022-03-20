#pragma once

#ifdef TB_PLATFORM_WINDOWS
	#ifdef TB_BUILD_DLL
		#define TB_API __declspec(dllexport)
	#else
		#define TB_API __declspec(dllimport)
	#endif
#else
	#error Turbo is supported in windows only
#endif
