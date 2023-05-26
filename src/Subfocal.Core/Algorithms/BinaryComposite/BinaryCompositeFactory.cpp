#include "stdafx.h"
#include "BinaryCompositeFactory.hpp"

BinaryCompositeFactory::BinaryCompositeFactory()
{
	_addAlgorithmFactory<CrossFade>();
}

std::string BinaryCompositeFactory::GetComponentName()
{
	return "BinaryCompositeFactory";
}