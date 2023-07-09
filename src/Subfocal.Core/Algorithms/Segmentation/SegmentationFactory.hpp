#pragma once
#include "KnnSegmentation.hpp"
#include "..\AlgorithmFactoryBase.hpp"

class SegmentationFactory : public AlgorithmFactoryBase
{
	SegmentationFactory();

	// Inherited via AlgorithmFactoryBase
	virtual std::string GetComponentName() override;
};

