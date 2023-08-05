#pragma once

#ifdef FX_PLATFORM_WINDOWS
	#ifdef FX_BUILD_DLL
		#define FRAMEX_API __declspec(dllexport)
	#else
		#define FRAMEX_API __declspec(dllimport)
	#endif
#else
	#error FrameX currently only supports Windows!
#endif

#ifdef FX_ENABLE_ASSERTS
	#define FX_ASSERT(x, ...) { if(!(x)) {FX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define FX_CORE_ASSERT(x, ...) { if(!(x)) { FX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FX_ASSERT(x, ...)
	#define FX_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)