#pragma once
#include "..\..\stdafx.h"
#include "IBinaryComposite.hpp"
#include "..\..\Utilities\Image\Normalize.hpp"
#include "..\..\Utilities\Image\Pyramid.hpp"

/// <summary>
/// Implements the multi-resolution spline proposed by Peter J. Burt and Edward H. Adelson. 
/// Peter J. Burt and Edward H. Adelson. 1983. A multiresolution spline with application to image mosaics. ACM Trans. Graph. 2, 4 (October 1983), 217–236. https://doi.org/10.1145/245.247
/// </summary>
class MultiResolutionSpline : public IBinaryComposite
{
public:
	MultiResolutionSpline();

	int Depth;

	virtual std::string GetComponentName() override;
	virtual cv::Mat Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask) override;

	/// <summary> Perform the splice on the laplacian pyramids and gaussian pyramids of the image and mask </summary>
	cv::Mat _spline(std::vector<cv::Mat> image1LaplacianPyramid, std::vector<cv::Mat> image2LaplacianPyramid, std::vector<cv::Mat> maskGaussianPyramid);

	/// <summary> Gets the edge of the passed in mask </summary>
	cv::Mat _getMaskEdge(cv::Mat thresholdedMask);

protected:
	cv::Mat _maskStructuringElement;

	/// <summary> Setup the structuring mask for creating the edge </summary>
	void _setupStructuringMask(int shape, int size);

	/// <summary> Create the image with the values between 0.0 and 1.0 where 0.0 takes the image from image1, and 1.0 from image2 </summary>
	cv::Mat _createBlendingImage(cv::Mat thresholdedMask, cv::Mat maskEdge);
};