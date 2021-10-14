#include "Logger.h"
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Rodinia {

	void Logger::Init() {
		//auto sharedFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("rodinia.log");
		//Logger::s_rLog = std::make_shared<spdlog::logger>("RodiniaLogger", sharedFileSink);
		//Logger::s_cLog = std::make_unique<spdlog::logger>("ClientLogger", sharedFileSink);
	}
}