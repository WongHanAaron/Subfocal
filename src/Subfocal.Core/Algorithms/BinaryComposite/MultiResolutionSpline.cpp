#include "stdafx.h"
#include "MultiResolutionSpline.hpp"

std::string MultiResolutionSpline::GetComponentName()
{
	return "MultiResolutionSpline";
}

cv::Mat MultiResolutionSpline::Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask)
{
	return cv::Mat();
}
