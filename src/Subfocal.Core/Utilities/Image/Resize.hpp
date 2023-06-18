#pragma once
#include "..\..\stdafx.h"

enum ResizeMode
{
	KeepAspectRatio = 0,
	KeepImageShape = 1,
	Crop = 2,
};

/// <summary> Helper class to handle resizing utilities </summary>
class Resize
{
public: 
	static cv::Mat ToFit(cv::Mat image, cv::Size size, ResizeMode mode, cv::InterpolationFlags interpolation = cv::InterpolationFlags::INTER_LINEAR);

	static cv::Mat ToFitWithAspectRatio(cv::Mat image, cv::Size size, cv::InterpolationFlags interpolation = cv::InterpolationFlags::INTER_LINEAR);

	static cv::Mat ToSize(cv::Mat image, cv::Size size, cv::InterpolationFlags interpolation = cv::InterpolationFlags::INTER_LINEAR);

	static cv::Mat ToCrop(cv::Mat image, cv::Size size);
};