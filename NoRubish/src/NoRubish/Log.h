#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include <iostream>

namespace NoRubish {

	class NR_API Log
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

//Core Logs
#define NR_CORE_ERROR(...) ::NoRubish::Log::GetCoreLogger()->error(__VA_ARGS__);
#define NR_CORE_TRACE(...) ::NoRubish::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define NR_CORE_INFO(...)  ::NoRubish::Log::GetCoreLogger()->info(__VA_ARGS__);
#define NR_CORE_WARN(...)  ::NoRubish::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define NR_CORE_FATAL(...) ::NoRubish::Log::GetCoreLogger()->fatal(__VA_ARGS__);

//Client Logs
#define NR_ERROR(...) ::NoRubish::Log::GetClientLogger()->error(__VA_ARGS__);
#define NR_TRACE(...) ::NoRubish::Log::GetClientLogger()->trace(__VA_ARGS__);
#define NR_INFO(...)  ::NoRubish::Log::GetClientLogger()->info(__VA_ARGS__);
#define NR_WARN(...)  ::NoRubish::Log::GetClientLogger()->warn(__VA_ARGS__);
#define NR_FATAL(...) ::NoRubish::Log::GetClientLogger()->fatal(__VA_ARGS__);