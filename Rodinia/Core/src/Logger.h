#pragma once
#include "Application.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace Rodinia {
	class RODINIA_API Logger {
	public:
		static void Init();
		static inline std::shared_ptr<spdlog::logger> getRodiniaLogger() { return nullptr; }
		static inline std::shared_ptr<spdlog::logger> getClientLogger() { return nullptr; }
	private:
		static std::shared_ptr<spdlog::logger> s_rLog;
		static std::shared_ptr<spdlog::logger> s_cLog;
	};

}
