#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"


namespace Turbo {

	class TB_API Log
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
#define TB_CORE_ERROR(...)::Turbo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TB_CORE_WARN(...)::Turbo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TB_CORE_INFO(...)::Turbo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TB_CORE_TRACE(...)::Turbo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TB_CORE_FATAL(...)::Turbo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TB_ERROR(...)::Turbo::Log::GetClientLogger()->error(__VA_ARGS__)
#define TB_WARN(...)::Turbo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TB_INFO(...)::Turbo::Log::GetClientLogger()->info(__VA_ARGS__)
#define TB_TRACE(...)::Turbo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TB_FATAL(...)::Turbo::Log::GetClientLogger()->fatal(__VA_ARGS__)
		  