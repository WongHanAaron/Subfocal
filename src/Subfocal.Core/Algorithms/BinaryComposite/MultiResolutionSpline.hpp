#pragma once
#include "..\..\stdafx.h"
#include "IBinaryComposite.hpp"

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
};