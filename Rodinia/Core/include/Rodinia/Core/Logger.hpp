#pragma once
#include <fmt/format.h>

namespace Rodinia {
	class ILogger {
	public:
		virtual void trace(const std::string& msg) = 0;
		virtual void info(const std::string& msg) = 0;
		virtual void warning(const std::string& msg) = 0;
		virtual void error(const std::string& msg) = 0;
		virtual void critical(const std::string& msg) = 0;

		// TODO: move fmt include inside implementation or check std::format  
		template <typename ...Args>
		void trace(const char* fmt, Args&&... args) {
			std::string msg = fmt::format(fmt, std::forward<Args>(args)...);
			this->trace(msg);
		};
		
		template <typename ...Args>
		void info(const char* fmt, Args&&... args) {
			std::string msg = fmt::format(fmt, std::forward<Args>(args)...);
			this->info(msg);
		};

		template <typename ...Args>
		void warning(const char* fmt, Args&&... args) {
			std::string msg = fmt::format(fmt, std::forward<Args>(args)...);
			this->warning(msg);
		};

		template <typename ...Args>
		void error(const char* fmt, Args&&... args) {
			std::string msg = fmt::format(fmt, std::forward<Args>(args)...);
			this->error(msg);
		};

		template <typename ...Args>
		void critical(const char* fmt, Args&&... args) {
			std::string msg = fmt::format(fmt, std::forward<Args>(args)...);
			this->critical(msg);
		};
	};

	class SpdLogger : public ILogger {
	public:
		SpdLogger(std::string name);
		~SpdLogger();

		void trace(const std::string& msg);
		void info(const std::string& msg);
		void warning(const std::string& msg);
		void error(const std::string& msg);
		void critical(const std::string& msg);
	private:
		class LoggerImpl;
		LoggerImpl* _impl;
	};

	class LoggerFacility {
	public:
		static inline std::shared_ptr<ILogger>& GetRodiniaLogger() { return _rLog; };
		static inline std::shared_ptr<ILogger>& GetClientLogger() { return _cLog; };
	private:
		static std::shared_ptr<ILogger> _rLog;
		static std::shared_ptr<ILogger> _cLog;
	};
}

#define RODINIA_INFO(...)     ::Rodinia::LoggerFacility::GetRodiniaLogger()->info(__VA_ARGS__)
#define RODINIA_TRACE(...)    ::Rodinia::LoggerFacility::GetRodiniaLogger()->trace(__VA_ARGS__)
#define RODINIA_WARNING(...)  ::Rodinia::LoggerFacility::GetRodiniaLogger()->warning(__VA_ARGS__)
#define RODINIA_ERROR(...)    ::Rodinia::LoggerFacility::GetRodiniaLogger()->error(__VA_ARGS__)
#define RODINIA_CRITICAL(...) ::Rodinia::LoggerFacility::GetRodiniaLogger()->critical(__VA_ARGS__)

#define CLIENT_INFO(...)     ::Rodinia::LoggerFacility::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_TRACE(...)    ::Rodinia::LoggerFacility::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_WARNING(...)  ::Rodinia::LoggerFacility::GetClientLogger()->warning(__VA_ARGS__)
#define CLIENT_ERROR(...)    ::Rodinia::LoggerFacility::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_CRITICAL(...) ::Rodinia::LoggerFacility::GetClientLogger()->critical(__VA_ARGS__)