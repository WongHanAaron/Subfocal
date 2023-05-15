#include "WindowImageLogger.hpp"

void WindowImageLogger::Log(const cv::Mat& image, const std::string& message)
{

}

void WindowImageLogger::Inject(DependencyProvider* provider)
{
	_screenSizeProvider = provider->GetService<IScreenSizeProvider>();
}

std::string WindowImageLogger::GetComponentName()
{
	return "WindowsImageLogger";
}
