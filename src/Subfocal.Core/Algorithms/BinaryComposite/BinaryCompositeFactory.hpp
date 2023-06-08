#pragma once
#include "..\AlgorithmFactoryBase.hpp"
#include "CrossFade.hpp"
#include "MultiResolutionSpline.hpp"

class BinaryCompositeFactory : public AlgorithmFactoryBase
{
public:
	BinaryCompositeFactory();

	virtual std::string GetComponentName() override;
};

