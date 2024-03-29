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

#ifdef TB_ENABLE_ASSERTS
	#define TB_ASSERT(x, ...) { if(!(x)) { TB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TB_CORE_ASSERT(x, ...) { if(!(x)) { TB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TB_ASSERT(x, ...)
	#define TB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)