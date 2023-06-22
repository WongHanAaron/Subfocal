#include "stdafx.h"
#include "ContentAwareResize.hpp"

std::string ContentAwareResize::GetComponentName()
{
    return "ContentAwareResize";
}

cv::Mat ContentAwareResize::Resize(cv::Mat input, cv::Size size)
{
    return cv::Mat();
}

cv::Mat ContentAwareResize::_calculateImageEnergy(cv::Mat image)
{
    return _calculateSobelImageEnergy(image);
}

cv::Mat ContentAwareResize::_calculateSobelImageEnergy(cv::Mat image)
{
    return cv::Mat();
}


