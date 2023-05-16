#pragma once
#include "..\..\stdafx.h"
#include "IImageLogger.hpp"
#include "../Environment/IScreenSizeProvider.hpp"

/// <summary> Implementation of the IImageLogger that displays the image to the screen size </summary>
class WindowImageLogger : public IImageLogger
{
public:

	void Log(const cv::Mat& image, const std::string& message = "");

	virtual void Inject(DependencyProvider* provider) override;

protected:
	std::shared_ptr<IScreenSizeProvider> _screenSizeProvider;

	// Inherited via IImageLogger
	virtual std::string GetComponentName() override;
};