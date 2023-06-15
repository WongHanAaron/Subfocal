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
