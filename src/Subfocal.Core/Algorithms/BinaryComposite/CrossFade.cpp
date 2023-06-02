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
	auto size = cv::Size(width + 2, width + 2);

	auto mask = cv::Mat(size, CV_8UC1, cv::Scalar(0));

	cv::circle(mask, cv::Point(size.width / 2, size.height / 2), width / 2, cv::Scalar(255), -1);
	cv::Mat kernel;
	cv::distanceTransform(mask, kernel, cv::DistanceTypes::DIST_C, 3, CV_32F);



	return mask;
}