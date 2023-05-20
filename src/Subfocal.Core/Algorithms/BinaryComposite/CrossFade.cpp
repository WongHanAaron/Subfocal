#include "stdafx.h"
#include "CrossFade.hpp"

std::string CrossFade::GetComponentName()
{
	return "CrossFade"; 
}

void CrossFade::SetConfiguration(Configuration config)
{
}

cv::Mat CrossFade::Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask1)
{
	return cv::Mat();
}
