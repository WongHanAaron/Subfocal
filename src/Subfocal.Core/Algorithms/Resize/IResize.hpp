#pragma once
#include "..\..\stdafx.h"
#include "..\Algorithm.hpp"

/// <summary>
/// The interface for an algorithm that resizes the image to the specified size
/// </summary>
class IResize : Algorithm
{
public:

	/// <summary>
	/// Resize the image to the specified size
	/// </summary>
	/// <param name="input">The input image to be resized</param>
	/// <param name="size">The size desired</param>
	/// <returns>The resized image</returns>
	virtual cv::Mat Resize(cv::Mat input, cv::Size size) = 0;
};