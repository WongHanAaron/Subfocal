#pragma once
#include "..\Algorithm.hpp"

/// <summary> The generic segmentation algorithm </summary>
class ISegmentation : public Algorithm
{
public:
	/// <summary>
	/// Segment the image into multiple segments. The returned image will be an image where each region 
	/// is discretized into a 16 bit image unique values for each region segmented
	/// </summary>
	virtual cv::Mat Segment(cv::Mat input) = 0;


	// Inherited via Algorithm
	virtual std::string GetComponentName() = 0;
};
