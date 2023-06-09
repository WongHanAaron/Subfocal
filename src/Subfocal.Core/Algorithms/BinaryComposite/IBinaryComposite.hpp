#pragma once
#include "..\..\stdafx.h"
#include "..\Algorithm.hpp"

/// <summary> The base class for performing compositing between two images </summary>
class IBinaryComposite : public Algorithm
{
public:
	/// <summary> Method to blend two images according to their mask values </summary>
	/// <param name="image1"> Image 1 to be blended </param>
	/// <param name="image2"> Image 2 to be blended </param>
	/// <param name="mask"> The mask of the region of Image 1 to keep in non-zero value </param>
	virtual cv::Mat Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask) = 0;
};