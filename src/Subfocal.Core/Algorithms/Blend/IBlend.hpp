#pragma once
#include <opencv2/core.hpp>

/// <summary> The base class for performing blending between two images </summary>
class IBlend
{
public:
	/// <summary> Method to blend two images according to their mask values </summary>
	/// <param name="image1"> Image 1 to be blended </param>
	/// <param name="image2"> Image 2 to be blended </param>
	/// <param name="mask1"> The mask of the region of Image 1 to keep in non-zero value </param>
	/// <param name="mask2"> The mask of the region of Image 2 to keep in non-zero value </param>
	/// <returns></returns>
	virtual cv::Mat Blend(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask1, const cv::Mat& mask2) = 0;
};