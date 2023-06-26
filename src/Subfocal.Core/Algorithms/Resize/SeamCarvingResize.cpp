#include "stdafx.h"
#include "SeamCarvingResize.hpp"

SeamCarvingResize::SeamCarvingResize()
{
    SetConfigurer("sobelwidth", [this](double val) -> void { this->SobelWidth = val; });
}

std::string SeamCarvingResize::GetComponentName()
{
    return "SeamCarvingResize";
}

cv::Mat SeamCarvingResize::Resize(cv::Mat input, cv::Size size)
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

bool SeamCarvingResize::_needResize(cv::Mat currentImage, cv::Size size)
{
    return currentImage.rows != size.width || currentImage.cols != size.height;
}

Seam SeamCarvingResize::_findSeamInX(cv::Mat energy)
{
    return Seam();
}

Seam SeamCarvingResize::_findSeamInY(cv::Mat energy)
{
    return Seam();
}

std::tuple<cv::Mat, cv::Mat> SeamCarvingResize::_calculateImageEnergy(cv::Mat image)
{
    return _calculateSobelImageEnergy(image);
}

std::tuple<cv::Mat, cv::Mat> SeamCarvingResize::_calculateSobelImageEnergy(cv::Mat image)
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


