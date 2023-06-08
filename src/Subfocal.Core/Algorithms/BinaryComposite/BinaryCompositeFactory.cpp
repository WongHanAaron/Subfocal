#include "stdafx.h"
#include "BinaryCompositeFactory.hpp"

BinaryCompositeFactory::BinaryCompositeFactory()
{
	_addAlgorithmFactory<CrossFade>();
	_addAlgorithmFactory<MultiResolutionSpline>();
}

std::string BinaryCompositeFactory::GetComponentName()
{
	return "BinaryCompositeFactory";
}