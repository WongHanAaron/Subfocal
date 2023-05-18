#include "stdafx.h"
#include "Resize.hpp"

cv::Mat Resize::ToFit(cv::Mat image, cv::Size size, bool keepAspectRatio, cv::InterpolationFlags interpolation)
{
	cv::Mat returned;
	if (keepAspectRatio)
	{

	}
	else
	{
		cv::resize(image, returned, size, 0.0, 0.0, interpolation);
	}
	return returned;
}