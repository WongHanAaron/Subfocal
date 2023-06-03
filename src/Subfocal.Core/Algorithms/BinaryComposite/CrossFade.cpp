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

	cv::filter2D(mask, fadedMask, CV_32FC1, kernel);

	if (_logger->IsEnabled(LogLevel::Trace))
		_logger->Trace({ mask, Normalize::Linear(kernel, 0.0, 255.0), fadedMask }, "mask, kernel, fadedMask");

	fadedMask = fadedMask / 255.0f;

	if (image1F.channels() == 3)
	{
		cv::Mat output;
		std::vector<cv::Mat> toMerge;
		toMerge.push_back(fadedMask);
		toMerge.push_back(fadedMask);
		toMerge.push_back(fadedMask);
		cv::merge(toMerge, output);
		fadedMask = output;
	}

	cv::Scalar one = image1F.channels() == 3 ? cv::Scalar(1.0, 1.0, 1.0) : cv::Scalar(1.0);

	//if (_logger->IsEnabled(LogLevel::Trace))
	//{
	//	_logger->Trace({ Normalize::Linear(fadedMask, 0.0, 255.0), Normalize::Linear((one - fadedMask), 0.0, 255.0) }, "Faded and non-faded mask");
	//}

	cv::multiply(image1F, fadedMask, image1F);
	cv::multiply(image2F, (one - fadedMask), image2F);
	
	cv::Mat mergedF = image1F + image2F;

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

	auto total = cv::sum(kernel);

	return kernel / total;
}