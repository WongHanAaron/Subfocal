#pragma once
#include <iostream>
#include "Logger.hpp"
#include "WindowImageLogger.hpp"
#include "../Environment/WindowsScreenSizeProvider.hpp"
#include "../Environment/DateTimeProvider.hpp"


/// <summary> Component for creating a logger component given the dependencies or the default dependencies </summary>
class LoggerFactory : public IInjectable
{
public: 
	inline std::string GetComponentName() { return "LoggerFactory"; }

	/// <summary> Create a logger with all default dependencies </summary>
	std::shared_ptr<Logger> Create();

	/// <summary> Create a logger with default cout writeline, context stack and datetime provider </summary>
	std::shared_ptr<Logger> Create(std::shared_ptr<IImageLogger> imageLogger);

	/// <summary> Create a logger with default cout writeline and context stack </summary>
	std::shared_ptr<Logger> Create(std::shared_ptr<IImageLogger> imageLogger, 
								   std::shared_ptr<IDateTimeProvider> dateTimeProvider);

	/// <summary> Create a logger with default cout writeline </summary>
	std::shared_ptr<Logger> Create(std::shared_ptr<IImageLogger> imageLogger,
		std::shared_ptr<IDateTimeProvider> dateTimeProvider,
		std::shared_ptr<ContextStack> contextStack);
};

