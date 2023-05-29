#include "stdafx.h"
#include "CrossFade.hpp"

CrossFade::CrossFade()
{
	SetConfigurer("width", [this](double val) -> void { this->Width = val; });
}

std::string CrossFade::GetComponentName()
{
	return "CrossFade"; 
}

cv::Mat CrossFade::Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask1)
{


	return cv::Mat();
}

cv::Mat CrossFade::_getKernel(int width)
{

	return cv::Mat();
}

cv::Mat CrossFade::_get1DKernel(int width)
{

	return cv::Mat(width, 1, CV_32FC1);
}
