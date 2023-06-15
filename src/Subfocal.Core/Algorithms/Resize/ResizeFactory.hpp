#pragma once
#include "..\AlgorithmFactoryBase.hpp"
#include "ContentAwareResize.hpp"

/// <summary> Algorithm for creating all resize algorithm operations </summary>
class ResizeFactory : public AlgorithmFactoryBase
{
public:

	ResizeFactory();

	// Inherited via AlgorithmFactoryBase
	virtual std::string GetComponentName() override;

};

