#include "stdafx.h"
#include "ContentAwareResize.hpp"

ContentAwareResize::ContentAwareResize()
{
    SetConfigurer("sobelwidth", [this](double val) -> void { this->SobelWidth = val; });
}

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

Seam ContentAwareResize::_findSeamInX(cv::Mat energy)
{
    return Seam();
}

Seam ContentAwareResize::_findSeamInY(cv::Mat energy)
{
    return Seam();
}

std::tuple<cv::Mat, cv::Mat> ContentAwareResize::_calculateImageEnergy(cv::Mat image)
{
    return _calculateSobelImageEnergy(image);
}

std::tuple<cv::Mat, cv::Mat> ContentAwareResize::_calculateSobelImageEnergy(cv::Mat image)
{
    cv::Mat input = image;

    if (input.channels() > 1)
    {
        cv::cvtColor(input, input, cv::COLOR_BGR2GRAY);
    }

    auto edge = Edge::Sobel(input, CV_32F, SobelWidth);

    cv::Mat xEdge = cv::abs(std::get<0>(edge));
    cv::Mat yEdge = cv::abs(std::get<1>(edge));

    cv::Mat output;
    cv::addWeighted(xEdge, 0.5, yEdge, 0.5, 0, output);

    return std::make_tuple(output, output);
}


