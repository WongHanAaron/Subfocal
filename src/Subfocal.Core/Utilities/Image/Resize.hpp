#pragma once
#include "..\..\stdafx.h"

/// <summary> Helper class to handle resizing utilities </summary>
class Resize
{
public: 
	static cv::Mat ToFit(cv::Mat image, cv::Size size, bool keepAspectRatio, cv::InterpolationFlags interpolation = cv::InterpolationFlags::INTER_LINEAR);


};