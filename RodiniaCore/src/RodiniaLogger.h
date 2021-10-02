#pragma once
#include <string>
#include <memory>

class RodiniaLogger {
public:
	virtual ~RodiniaLogger() = default;
	virtual void trace(std::string entry) = 0;
	virtual void info(std::string entry) = 0;
	virtual void warn(std::string entry) = 0;
	virtual void error(std::string entry) = 0;
};

using Logger = std::shared_ptr<RodiniaLogger>;