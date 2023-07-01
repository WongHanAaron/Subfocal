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
    auto priorImageSobel = Edge::Sobel(priorImage, CV_32FC1, Width);
    auto priorImageX = std::get<0>(priorImageSobel);
    auto priorImageY = std::get<1>(priorImageSobel);

    cv::Mat priorImageX2, priorImageY2, priorImageXY;

    cv::multiply(priorImageX, priorImageX, priorImageX2);
    cv::multiply(priorImageY, priorImageY, priorImageY2);
    cv::multiply(priorImageX, priorImageY, priorImageXY);



    return cv::Mat();
}
