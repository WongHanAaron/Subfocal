#pragma once
#include "IResize.hpp"

class ContentAwareResize : public IResize
{
public:
	// Inherited via IResize
	virtual std::string GetComponentName() override;
	
	virtual cv::Mat Resize(cv::Mat input, cv::Size size) override;

	cv::Mat _calculateImageEnergy(cv::Mat image);

	cv::Mat _calculateSobelImageEnergy(cv::Mat image);
};

