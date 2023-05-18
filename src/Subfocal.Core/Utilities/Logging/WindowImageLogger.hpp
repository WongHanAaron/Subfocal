#pragma once
#include "..\..\stdafx.h"
#include "IImageLogger.hpp"
#include "../Environment/IScreenSizeProvider.hpp"

/// <summary> Implementation of the IImageLogger that displays the image to the screen size </summary>
class WindowImageLogger : public IImageLogger
{
public:

	virtual void Log(const cv::Mat& image, const std::string& message = "") override;

	virtual void Log(std::initializer_list<cv::Mat> images, const std::string& message = "") override;

	virtual void Inject(DependencyProvider* provider) override;

protected:
	std::shared_ptr<IScreenSizeProvider> _screenSizeProvider;

	virtual std::string GetComponentName() override;

	void DisplayAndWait(cv::Mat image, const std::string& message = "");
};