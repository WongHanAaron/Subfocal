#include "stdafx.h"
#include "MultiResolutionSpline.hpp"

MultiResolutionSpline::MultiResolutionSpline()
{
	SetConfigurer("depth", [this](double val) -> void { this->Depth = val; }, -1, false);
}

std::string MultiResolutionSpline::GetComponentName()
{
	return "MultiResolutionSpline";
}

cv::Mat MultiResolutionSpline::Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask)
{
	auto image1Pyramid = Pyramid::GetGaussian(image1, Depth);
	auto image2Pyramid = Pyramid::GetGaussian(image2, Depth);
	auto maskPyramid = Pyramid::GetGaussian(mask, Depth);

	if (_logger->IsEnabled(LogLevel::Trace))
	{
		_logger->Trace(image1Pyramid, "Image1");
		_logger->Trace(image2Pyramid, "Image2");
		_logger->Trace(maskPyramid, "Mask");
	}

	auto image1Laplacian = Pyramid::GetLaplacian(image1Pyramid);
	auto image2Laplacian = Pyramid::GetLaplacian(image2Pyramid);

	if (_logger->IsEnabled(LogLevel::Trace))
	{
		_logger->Trace(image1Laplacian, "Image1");
		_logger->Trace(image2Laplacian, "Image2");
	}

	return cv::Mat();
}
