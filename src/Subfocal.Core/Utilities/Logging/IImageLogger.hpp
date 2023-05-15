#pragma once
#include <opencv2/core.hpp>
#include <string>
#include "..\DependencyInjection\IInjectable.hpp"

/// <summary> The utility class for logging images </summary>
class IImageLogger : public IInjectable
{
public:
	virtual void Log(const cv::Mat& image, const std::string& message = "") = 0;
};