#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "IImageLogger.hpp"

/// <summary> Implementation of the IImageLogger that displays the image to the screen size </summary>
class WindowImageLogger : IImageLogger
{
public:
	void Log(const cv::Mat& image, const std::string& message = "");
};

