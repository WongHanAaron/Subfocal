#include "stdafx.h"
#include "HornSchunckOpticalFlow.hpp"

HornSchunckOpticalFlow::HornSchunckOpticalFlow()
{
    SetConfigurer("width", [this](double val) -> void { this->Width = val; });
}

std::string HornSchunckOpticalFlow::GetComponentName()
{
    return "HornSchunckOpticalFlow";
}

cv::Mat HornSchunckOpticalFlow::GetFlow(cv::Mat priorImage, cv::Mat nextImage, cv::Mat flowSeed)
{


    return cv::Mat();
}
