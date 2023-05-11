#include "Logger.hpp"

Logger::Logger(std::function<void(std::string)> writeLine, 
	           std::shared_ptr<IImageLogger> imageLogger, 
	           std::shared_ptr<IDateTimeProvider> dateTimeProvider,
			   std::shared_ptr<ContextStack> contextStack)
{
	_writeLine = writeLine;
	_imageLogger = imageLogger;
	_dateTimeProvider = dateTimeProvider;
	_contextStack = contextStack;
}

void Logger::EnterContext(const std::string& contextName, const std::map<std::string, std::string>& context) 
{

}

void Logger::LeaveContext()
{

}

void Logger::Trace(const std::string& message) { }
void Logger::Debug(const std::string& message) { }
void Logger::Info(const std::string& message) { }
void Logger::Warn(const std::string& message) { }
void Logger::Error(const std::string& message) { }

void Logger::Trace(const cv::Mat image, const std::string& message) { }
void Logger::Debug(const cv::Mat image, const std::string& message) { }
bool Logger::IsEnabled(enum LogLevel level) { return true; }