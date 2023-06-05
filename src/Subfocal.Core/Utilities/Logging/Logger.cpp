#include "stdafx.h"
#include "Logger.hpp"

void Logger::Inject(DependencyProvider* provider)
{
	_writeLine = [](std::string s) { std::cout << s << std::endl; };
	_imageLogger = provider->GetService<IImageLogger>();
	_dateTimeProvider = provider->GetService<IDateTimeProvider>();
	_contextStack = provider->GetService<IContextStack>();
}

void Logger::EnterContext(const std::string& contextName, const std::map<std::string, std::string>& context) 
{

}

void Logger::LeaveContext()
{

}

void Logger::Trace(const std::string& message) { LogIfEnabled(LogLevel::Trace, message); }
void Logger::Debug(const std::string& message) { LogIfEnabled(LogLevel::Debug, message); }
void Logger::Info(const std::string& message) { LogIfEnabled(LogLevel::Info, message); }
void Logger::Warn(const std::string& message) { LogIfEnabled(LogLevel::Warn, message); }
void Logger::Error(const std::string& message) { LogIfEnabled(LogLevel::Error, message); }
void Logger::LogIfEnabled(enum LogLevel level, const std::string& str)
{
	if (IsEnabled(level)) _writeLine(GetPrefix(level) + str);
}

std::string Logger::GetPrefix(enum LogLevel level)
{
	switch (level)
	{
	case LogLevel::Trace:
		return "Trace: ";
	case LogLevel::Debug:
		return "Debug: ";
	case LogLevel::Info:
		return "Info: ";
	case LogLevel::Warn:
		return "Warn: ";
	case LogLevel::Error:
		return "Error: ";
	default:
		return "";
	}
}

void Logger::Trace(const cv::Mat& image, const std::string& message) 
{
	LogIfEnabled(LogLevel::Trace, image, message);
}

void Logger::Debug(const cv::Mat& image, const std::string& message) 
{
	LogIfEnabled(LogLevel::Debug, image, message);
}

void Logger::Trace(std::initializer_list<cv::Mat> images, const std::string& message)
{
	LogIfEnabled(LogLevel::Trace, images, message);
}

void Logger::Debug(std::initializer_list<cv::Mat> images, const std::string& message)
{
	LogIfEnabled(LogLevel::Debug, images, message);
}

void Logger::Trace(std::vector<cv::Mat> images, const std::string& message)
{
	LogIfEnabled(LogLevel::Trace, images, message);
}

void Logger::Debug(std::vector<cv::Mat> images, const std::string& message)
{
	LogIfEnabled(LogLevel::Debug, images, message);
}

void Logger::LogIfEnabled(enum LogLevel level, const cv::Mat& image, const std::string& message)
{
	if (IsEnabled(level))
	{
		_imageLogger->Log(image, GetPrefix(level) + message);
	}
}

void Logger::LogIfEnabled(enum LogLevel level, std::initializer_list<cv::Mat> images, const std::string& message)
{
	if (IsEnabled(level))
	{
		_imageLogger->Log(images, GetPrefix(level) + message);
	}
}

void Logger::LogIfEnabled(enum LogLevel level, std::vector<cv::Mat> images, const std::string& message)
{
	if (IsEnabled(level))
	{
		_imageLogger->Log(images, GetPrefix(level) + message);
	}
}

bool Logger::IsEnabled(enum LogLevel level) 
{
	return (int)LogLevel <= (int)level;
}