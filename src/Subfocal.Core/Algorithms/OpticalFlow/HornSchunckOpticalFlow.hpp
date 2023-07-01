#pragma once
#include "IOpticalFlow.hpp"
#include "..\..\Utilities\Image\Edge.hpp"

/// <summary>
/// Implementation of the Horn-Schnuck Optical Flow Algorithm
/// </summary>
class HornSchunckOpticalFlow : public IOpticalFlow
{
public:

	HornSchunckOpticalFlow();

	/// <summary> Width of the smoothness criteria </summary>
	int Width;

	// Inherited via Algorithm
	virtual std::string GetComponentName() override;

	// Inherited via IOpticalFlow
	virtual cv::Mat GetFlow(cv::Mat priorImage, cv::Mat nextImage, cv::Mat flowSeed) override;
};

