#pragma once
#include "..\..\stdafx.h"

class Pyramid
{
public:
	/// <summary> Gets a gaussian pyramid with the specified count of layers. </summary>
	static std::vector<cv::Mat> GetGaussian(const cv::Mat image, int layers = -1);

	/// <summary> Gets a laplacian pyramid with the specified count of layers. </summary>
	static std::vector<cv::Mat> GetLaplacian(const cv::Mat image, int layers = -1);

	/// <summary> Gets a laplacian pyramid from the passed in Gaussian pyramid </summary>
	static std::vector<cv::Mat> GetLaplacian(const std::vector<cv::Mat> gaussianPyramid);
};

