#include "LoggerFactory.hpp"

std::shared_ptr<Logger> LoggerFactory::Create()
{
	auto defaultImageLogger = std::dynamic_pointer_cast<IImageLogger, WindowImageLogger>(
									std::make_shared<WindowImageLogger>(
										std::dynamic_pointer_cast<IScreenSizeProvider, WindowsScreenSizeProvider>(
											std::make_shared<WindowsScreenSizeProvider>())));

	return Create(defaultImageLogger);
}


std::shared_ptr<Logger> LoggerFactory::Create(std::shared_ptr<IImageLogger> imageLogger)
{
	auto defaultDateTimeProvider = std::dynamic_pointer_cast<IDateTimeProvider, DateTimeProvider>(
										std::make_shared<DateTimeProvider>());
	return Create(imageLogger, defaultDateTimeProvider);
}

std::shared_ptr<Logger> LoggerFactory::Create(std::shared_ptr<IImageLogger> imageLogger, std::shared_ptr<IDateTimeProvider> dateTimeProvider)
{
	return Create(imageLogger, dateTimeProvider, std::make_shared<ContextStack>());
}

std::shared_ptr<Logger> LoggerFactory::Create(std::shared_ptr<IImageLogger> imageLogger, std::shared_ptr<IDateTimeProvider> dateTimeProvider, std::shared_ptr<ContextStack> contextStack)
{
	return std::make_shared<Logger>([](std::string message) { std::cout << message << std::endl; }, imageLogger, dateTimeProvider, contextStack);
}