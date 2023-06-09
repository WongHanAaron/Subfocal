#include "stdafx.h"
#include "Resize.hpp"

cv::Mat Resize::ToFit(cv::Mat image, cv::Size size, ResizeMode mode, cv::InterpolationFlags interpolation)
{
	cv::Mat returned;
	switch (mode)
	{
	case ResizeMode::KeepAspectRatio:
		return ToFitWithAspectRatio(image, size, interpolation);
	case ResizeMode::KeepImageShape:
		return ToSize(image, size, interpolation);
	case ResizeMode::Crop:
		return ToCrop(image, size);
	}
	return returned;
}

cv::Mat Resize::ToFitWithAspectRatio(cv::Mat image, cv::Size size, cv::InterpolationFlags interpolation)
{
	cv::Mat returned;

	auto background = image.channels() == 4 ? cv::Scalar(0, 0, 0, 0) :
		image.channels() == 3 ? cv::Scalar(0, 0, 0) :
		cv::Scalar(0);
	returned = cv::Mat(size, image.type(), background);
	cv::Mat resized;
	cv::Size resizedSize;
	auto aspectRatio = (float)image.size().width / (float)image.size().height;
	auto outputAspectRatio = (float)size.width / (float)size.height;

	if (aspectRatio == outputAspectRatio)
	{
		resizedSize = cv::Size(size.width, size.height);
		cv::resize(image, resized, resizedSize, 0.0, 0.0, interpolation);
	}
	else if (aspectRatio > outputAspectRatio)
	{
		// If the input image is wider than the output, the input image is restricted in width
		// scale the input image by the width
		auto scale = (float)size.width / (float)image.size().width;
		auto newHeight = image.size().height * scale;
		resizedSize = cv::Size(size.width, newHeight);
		cv::resize(image, resized, resizedSize, 0.0, 0.0, interpolation);
	}
	else
	{
		// If the input image is thinner than the output, the input image is restricted in height
		// scale the input image by the height
		auto scale = (float)size.height / (float)image.size().height;
		auto newWidth = image.size().width * scale;
		resizedSize = cv::Size(newWidth, size.height);
		cv::resize(image, resized, resizedSize, 0.0, 0.0, interpolation);
	}

	int x_tl = (size.width - resizedSize.width) / 2;
	int y_tl = (size.height - resizedSize.height) / 2;

	resized.copyTo(returned(cv::Rect(x_tl, y_tl, resizedSize.width, resizedSize.height)));

	return returned;
}

cv::Mat Resize::ToSize(cv::Mat image, cv::Size size, cv::InterpolationFlags interpolation)
{
	cv::Mat returned;
	cv::resize(image, returned, size, 0.0, 0.0, interpolation);
	return returned;
}

cv::Mat Resize::ToCrop(cv::Mat image, cv::Size size)
{
	cv::Mat max = cv::Mat(cv::Size(std::max(image.cols, size.width), std::max(image.rows, size.height)), image.type());

	image.copyTo(max(cv::Rect(0, 0, image.cols, image.rows)));

	return max(cv::Rect(0, 0, size.width, size.height)); 
}
