#pragma once

#include "..\..\stdafx.h"
#include "..\Algorithm.hpp"

/// <summary> Base interface for optical flow methods </summary>
class IOpticalFlow : public Algorithm
{
public:

	/// <summary>
	/// Gets the flow between the priorImage and the nextImage
	/// </summary>
	/// <param name="priorImage">the image the flow will be calculated from</param>
	/// <param name="nextImage">the image the flow will be calculated to</param>
	/// <param name="flowSeed">any initial flow state that can be passed to the algorithm</param>
	/// <returns>a 2 dimensional image with the flow in X and Y</returns>
	virtual cv::Mat GetFlow(cv::Mat priorImage, cv::Mat nextImage, cv::Mat flowSeed = cv::Mat()) = 0;

};