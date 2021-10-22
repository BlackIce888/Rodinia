#include "Rodinia/Core/Logger.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Rodinia {
    std::shared_ptr<ILogger> LoggerFacility::_rLog = std::make_shared<SpdLogger>("RODINIA");
    std::shared_ptr<ILogger> LoggerFacility::_cLog = std::make_shared<SpdLogger>("CLIENT");

    class SpdLogger::LoggerImpl {
    public:
        explicit LoggerImpl(std::string name, ILogger* pubInterface) :
            _pubInterface(pubInterface) {
            _sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            _logger = std::make_shared<spdlog::logger>(name, _sink);
            spdlog::initialize_logger(_logger);
        }

        std::shared_ptr<spdlog::logger>& GetLogger() {
            return _logger;
        }

    private:
        ILogger* _pubInterface;
        std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> _sink;
        std::shared_ptr<spdlog::logger> _logger;
    };

    SpdLogger::SpdLogger(std::string name) {
        _impl = new LoggerImpl(name, this);
    }
    SpdLogger::~SpdLogger() {
        delete(_impl);
    }

    void SpdLogger::trace(const std::string& msg) {
        _impl->GetLogger()->trace(msg);
    }

    void SpdLogger::info(const std::string& msg) {
        _impl->GetLogger()->info(msg);
    }

    void SpdLogger::warning(const std::string& msg) {
        _impl->GetLogger()->warn(msg);
    }

    void SpdLogger::error(const std::string& msg) {
        _impl->GetLogger()->error(msg);
    }

    void SpdLogger::critical(const std::string& msg) {
        _impl->GetLogger()->critical(msg);
    }
}