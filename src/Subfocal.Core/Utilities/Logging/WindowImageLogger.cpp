#include "stdafx.h"
#include "WindowImageLogger.hpp"

void WindowImageLogger::Log(const cv::Mat& image, const std::string& message)
{
	if (image.empty()) return;

	auto width = std::ceil(_screenSizeProvider->GetWidth() * 0.9);
	auto height = std::ceil(_screenSizeProvider->GetHeight() * 0.9);
	
	auto toBeShown = Resize::ToFit(image, cv::Size(width, height), true);

	DisplayAndWait(toBeShown, message);
}

void WindowImageLogger::Log(std::initializer_list<cv::Mat> images, const std::string& message)
{
	std::vector<cv::Mat> toMontage;

	for (auto& m : images)
	{
		toMontage.push_back(m);
	}

	Log(toMontage, message);
}

void WindowImageLogger::Log(std::vector<cv::Mat> images, const std::string& message)
{
	auto width = std::ceil(_screenSizeProvider->GetWidth() * 0.9);
	auto height = std::ceil(_screenSizeProvider->GetHeight() * 0.9);

	auto montage = Montage::Make(images, 10, width, height);

	DisplayAndWait(montage, message);
}

void WindowImageLogger::Inject(DependencyProvider* provider)
{
	_screenSizeProvider = provider->GetService<IScreenSizeProvider>();
}

void WindowImageLogger::DisplayAndWait(cv::Mat image, const std::string& message)
{
	cv::imshow(message, image);
	cv::waitKey(-1);
	cv::destroyWindow(message);
}

std::string WindowImageLogger::GetComponentName()
{
	return "WindowsImageLogger";
}
