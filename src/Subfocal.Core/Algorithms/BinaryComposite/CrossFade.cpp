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
	auto kernel = _getKernel(Width);
	cv::Mat fadedMask, image1F, image2F;

	image1.convertTo(image1F, CV_32FC1);
	image2.convertTo(image2F, CV_32FC1);

	cv::Mat mask = mask1;

	if (mask.channels() == 3)
	{
		cv::cvtColor(mask, mask, cv::COLOR_BGR2GRAY);
	}

	cv::filter2D(mask1, fadedMask, CV_32FC1, kernel);

	fadedMask = fadedMask / 255.0f;

	cv::Mat mergedF = image1F * fadedMask + image2F * (1.0f - fadedMask);

	cv::Mat output;

	mergedF.convertTo(output, image1.type());

	return output;
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