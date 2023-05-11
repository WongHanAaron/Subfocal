#pragma once
#include <string>
#include <functional>
#include <map>
#include <opencv2/core.hpp>
#include "..\Environment\IDateTimeProvider.hpp"
#include "IImageLogger.hpp"
#include "ContextStack.hpp"

enum LogLevel {
	Trace = 0,
	Debug = 1,
	Info = 2,
	Warn = 3,
	Error = 4
};

class Logger
{
public:
	Logger(std::function<void(std::string)> writeLine, 
		   std::shared_ptr<IImageLogger> imageLogger, 
		   std::shared_ptr<IDateTimeProvider> dateTimeProvider,
		   std::shared_ptr<ContextStack> contextStack);
	
	/// <summary> The log level for this logger </summary>
	LogLevel LogLevel;

	/// <summary> Flag for if we should log images </summary>
	bool ShouldLogImages;

	/// <summary> Enter a new functional context with additional context information </summary>
	void EnterContext(const std::string& contextName, const std::map<std::string, std::string>& context);
	
	/// <summary> Leave the most recent context </summary>
	void LeaveContext();

	void Trace(const std::string& message);
	void Debug(const std::string& message);
	void Info(const std::string& message);
	void Warn(const std::string& message);
	void Error(const std::string& message);

	void Trace(const cv::Mat image, const std::string& message = "");
	void Debug(const cv::Mat image, const std::string& message = "");

protected:
	/// <summary> The method for writing a logging </summary>
	std::function<void(std::string)> _writeLine;

	/// <summary> The component to perform image logging </summary>
	std::shared_ptr<IImageLogger> _imageLogger;

	/// <summary> The component for providing the date time </summary>
	std::shared_ptr<IDateTimeProvider> _dateTimeProvider;

	/// <summary> The component for storing the logging contexts in a stack </summary>
	std::shared_ptr<ContextStack> _contextStack;

	/// <summary> Checks if the passed in level is enabled for logging </summary>
	bool IsEnabled(enum LogLevel level);
};

