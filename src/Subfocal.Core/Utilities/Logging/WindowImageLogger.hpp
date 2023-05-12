#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "IImageLogger.hpp"
#include "../Environment/IScreenSizeProvider.hpp"

/// <summary> Implementation of the IImageLogger that displays the image to the screen size </summary>
class WindowImageLogger : IImageLogger
{
public:
	WindowImageLogger(std::shared_ptr<IScreenSizeProvider> screenSizeProvider);

	void Log(const cv::Mat& image, const std::string& message = "");

protected:
	std::shared_ptr<IScreenSizeProvider> _screenSizeProvider;
};