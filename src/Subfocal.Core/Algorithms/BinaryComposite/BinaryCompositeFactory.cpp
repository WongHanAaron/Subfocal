#include "stdafx.h"
#include "BinaryCompositeFactory.hpp"

BinaryCompositeFactory::BinaryCompositeFactory()
{
	_addAlgorithmFactory<CrossFade>();
}