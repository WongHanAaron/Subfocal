#pragma once
#include "..\AlgorithmFactoryBase.hpp"
#include "HornSchunckOpticalFlow.hpp"

class OpticalFlowFactory : public AlgorithmFactoryBase
{
public:

	OpticalFlowFactory();

	// Inherited via AlgorithmFactoryBase
	virtual std::string GetComponentName() override;
};

