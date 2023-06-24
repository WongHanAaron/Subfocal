#pragma once
#include "..\..\stdafx.h"

class Edge
{
public:
	static std::tuple<cv::Mat, cv::Mat> Sobel(cv::Mat image, int outputDepth, int kernelSize, int borderType = cv::BorderTypes::BORDER_DEFAULT);

	static std::tuple<cv::Mat, cv::Mat> SobelSingle(cv::Mat image, int outputDepth, int kernelSize, int borderType = cv::BorderTypes::BORDER_DEFAULT);
};