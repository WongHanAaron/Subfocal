#include "stdafx.h"
#include "Normalize.hpp"

cv::Mat Normalize::Linear(cv::Mat input, int min, int max)
{
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(input, &minVal, &maxVal, &minLoc, &maxLoc);

    auto range = maxVal - minVal;
    
    if (range <= 0)
        range = 0.001;

    auto newRange = max - min;

    if (newRange <= 0)
        newRange = 0.001;

    return (input - minVal) / (range / newRange) + min;
}

cv::Mat Normalize::Linear(cv::Mat input, double min, double max)
{
    if (input.type() == CV_8UC1)
        input.convertTo(input, CV_32FC1);
    if (input.type() == CV_8UC2)
        input.convertTo(input, CV_32FC2);
    if (input.type() == CV_8UC3)
        input.convertTo(input, CV_32FC3);

    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(input, &minVal, &maxVal, &minLoc, &maxLoc);

    auto range = maxVal - minVal;

    if (range <= 0)
        range = 0.001;

    auto newRange = max - min;

    if (newRange <= 0)
        newRange = 0.001;

    return (input - minVal) / (range / newRange) + min;
}
