#pragma once
#include "IResize.hpp"
#include "..\..\Utilities\Image\Edge.hpp"
#include "..\..\Models\Resize\Seam.hpp"

/// <summary>
/// Content aware resize as described in the paper "Seam Carving for Content-Aware Image Resizing"
/// by Shai Avidan
/// </summary>
class SeamCarvingResize : public IResize
{
public:

	SeamCarvingResize();

	/// <summary> The kernel width for the sobel operation </summary>
	int SobelWidth = 3;

	// Inherited via IResize
	virtual std::string GetComponentName() override;
	
	virtual cv::Mat Resize(cv::Mat input, cv::Size size) override;

	/// <summary> Returns if the current image still needs a resize </summary>
	bool _needResize(cv::Mat currentImage, cv::Size targetSize);

	/// <summary> Finds a seam in the X direction </summary>
	Seam _findSeamInX(cv::Mat energy);

	/// <summary> Finds a seam in the Y direction </summary>
	Seam _findSeamInY(cv::Mat energy);

	/// <summary> Returns the image energy </summary>
	std::tuple<cv::Mat, cv::Mat> _calculateImageEnergy(cv::Mat image);

	/// <summary> Returns the image energy from the sobel edge </summary>
	std::tuple<cv::Mat, cv::Mat> _calculateSobelImageEnergy(cv::Mat image);
};

