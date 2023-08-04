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

#define BIT(x) (1 << x)