#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace FrameX {

	class FRAMEX_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define FX_CORE_TRACE(...)    ::FrameX::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FX_CORE_INFO(...)     ::FrameX::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FX_CORE_WARN(...)     ::FrameX::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FX_CORE_ERROR(...)    ::FrameX::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client log macros
#define FX_TRACE(...)         ::FrameX::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FX_INFO(...)          ::FrameX::Log::GetClientLogger()->info(__VA_ARGS__)
#define FX_WARN(...)          ::FrameX::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FX_ERROR(...)         ::FrameX::Log::GetClientLogger()->error(__VA_ARGS__)