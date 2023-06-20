#pragma once
#include "IOpticalFlow.hpp"

/// <summary>
/// Implementation of the Horn-Schnuck Optical Flow Algorithm
/// </summary>
class HornSchunckOpticalFlow : public IOpticalFlow
{
public:

	HornSchunckOpticalFlow();

	// Inherited via Algorithm
	virtual std::string GetComponentName() override;

};

