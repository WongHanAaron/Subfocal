#include "stdafx.h"
#include "SegmentationFactory.hpp"

SegmentationFactory::SegmentationFactory()
{
	_addAlgorithmFactory<KnnSegmentation>();
}

std::string SegmentationFactory::GetComponentName()
{
	return "SegmentationFactory";
}
