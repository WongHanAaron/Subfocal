#pragma once
#include "..\..\stdafx.h"
#include "..\..\Models\Configuration\Configurable.hpp"
#include "..\DependencyInjection\IInjectable.hpp"
#include "..\Environment\IDateTimeProvider.hpp"
#include "IImageLogger.hpp"
#include "IContextStack.hpp"

enum LogLevel {
	Trace = 0,
	Debug = 1,
	Info = 2,
	Warn = 3,
	Error = 4
};

class Logger : public Configurable
{
public:

	void Inject(DependencyProvider* provider);

	inline std::string GetComponentName() { return "Logger"; }

	/// <summary> The log level for this logger </summary>
	LogLevel LogLevel = LogLevel::Debug;

	/// <summary> Flag for if we should log images </summary>
	bool ShouldLogImages;

	/// <summary> Enter a new functional context with additional context information </summary>
	void EnterContext(const std::string& contextName, const std::map<std::string, std::string>& context);
	
	/// <summary> Leave the most recent context </summary>
	void LeaveContext();

	/// <summary> Checks if the passed in level is enabled for logging </summary>
	bool IsEnabled(enum LogLevel level);

	void Trace(const std::string& message);
	void Debug(const std::string& message);
	void Info(const std::string& message);
	void Warn(const std::string& message);
	void Error(const std::string& message);

	void Trace(const cv::Mat& image, const std::string& message = "");
	void Debug(const cv::Mat& image, const std::string& message = "");

	void Trace(std::initializer_list<cv::Mat> images, const std::string& message = "");
	void Debug(std::initializer_list<cv::Mat> images, const std::string& message = "");

	void Trace(std::vector<cv::Mat> images, const std::string& message = "");
	void Debug(std::vector<cv::Mat> images, const std::string& message = "");

protected:
	/// <summary> The method for writing a logging </summary>
	std::function<void(std::string)> _writeLine;

	/// <summary> The component to perform image logging </summary>
	std::shared_ptr<IImageLogger> _imageLogger;

	/// <summary> The component for providing the date time </summary>
	std::shared_ptr<IDateTimeProvider> _dateTimeProvider;

	/// <summary> The component for storing the logging contexts in a stack </summary>
	std::shared_ptr<IContextStack> _contextStack;

	/// <summary> Writes a log with the log function if this log level is enabled </summary>
	void LogIfEnabled(enum LogLevel level, const std::string& str);

	/// <summary> Gets the prefix given a log level </summary>
	std::string GetPrefix(enum LogLevel level);

	/// <summary> Writes the image log if the log level is enabled </summary>
	void LogIfEnabled(enum LogLevel level, const cv::Mat& image, const std::string& message);

	/// <summary> Writes the image collection log if the log level is enabled </summary>
	void LogIfEnabled(enum LogLevel level, std::initializer_list<cv::Mat> images, const std::string& message);

	/// <summary> Writes the image collection log if the log level is enabled </summary>
	void LogIfEnabled(enum LogLevel level, std::vector<cv::Mat> images, const std::string& message);
};

