#include "stdafx.h"
#include "ContentAwareResize.hpp"

std::string ContentAwareResize::GetComponentName()
{
    return "ContentAwareResize";
}

cv::Mat ContentAwareResize::Resize(cv::Mat input, cv::Size size)
{
    cv::Mat currentImage = input;
    
    while (_needResize(currentImage, size))
    {
        auto imageEnergies = _calculateImageEnergy(currentImage);
        auto imageEnergyInX = std::get<0>(imageEnergies);
        auto imageEnergyInY = std::get<1>(imageEnergies);

        auto xSeam = _findSeamInX(imageEnergyInX);
        auto ySeam = _findSeamInX(imageEnergyInY);


    }

    return cv::Mat();
}

bool ContentAwareResize::_needResize(cv::Mat currentImage, cv::Size size)
{
    return currentImage.rows != size.width || currentImage.cols != size.height;
}

std::tuple<cv::Mat, cv::Mat> ContentAwareResize::_calculateImageEnergy(cv::Mat image)
{
    return _calculateSobelImageEnergy(image);
}

std::tuple<cv::Mat, cv::Mat> ContentAwareResize::_calculateSobelImageEnergy(cv::Mat image)
{
    return std::make_tuple(cv::Mat(), cv::Mat());
}


