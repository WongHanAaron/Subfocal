#pragma once
#include "..\..\stdafx.h"
#include "..\DependencyInjection\IInjectable.hpp"

/// <summary> The utility class for logging images </summary>
class IImageLogger : public IInjectable
{
public:
	virtual void Log(const cv::Mat& image, const std::string& message = "") = 0;
	virtual void Log(std::initializer_list<cv::Mat> images, const std::string& message = "") = 0;
};