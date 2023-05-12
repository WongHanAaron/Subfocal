#include "WindowImageLogger.hpp"


WindowImageLogger::WindowImageLogger(std::shared_ptr<IScreenSizeProvider> screenSizeProvider)
{
	_screenSizeProvider = screenSizeProvider;
}

void WindowImageLogger::Log(const cv::Mat& image, const std::string& message)
{

}