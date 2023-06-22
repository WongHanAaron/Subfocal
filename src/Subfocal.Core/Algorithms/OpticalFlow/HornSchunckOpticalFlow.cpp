#include "stdafx.h"
#include "HornSchunckOpticalFlow.hpp"

HornSchunckOpticalFlow::HornSchunckOpticalFlow()
{
}

std::string HornSchunckOpticalFlow::GetComponentName()
{
    return "HornSchunckOpticalFlow";
}

cv::Mat HornSchunckOpticalFlow::GetFlow(cv::Mat priorImage, cv::Mat nextImage, cv::Mat flowSeed)
{


    return cv::Mat();
}
