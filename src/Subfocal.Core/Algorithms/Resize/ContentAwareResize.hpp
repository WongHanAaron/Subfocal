#pragma once
#include "IResize.hpp"

class ContentAwareResize : public IResize
{
	// Inherited via IResize
	virtual std::string GetComponentName() override;
	
	virtual cv::Mat Resize(cv::Mat input, cv::Size size) override;
};

