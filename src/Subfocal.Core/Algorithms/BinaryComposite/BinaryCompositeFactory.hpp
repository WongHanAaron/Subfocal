#pragma once
#include "..\AlgorithmFactoryBase.hpp"
#include "CrossFade.hpp"
#include "MultiResolutionSpline.hpp"

/// <summary> Factory class for creating all the binary composite algorithms </summary>
class BinaryCompositeFactory : public AlgorithmFactoryBase
{
public:
	BinaryCompositeFactory();

	virtual std::string GetComponentName() override;
};

