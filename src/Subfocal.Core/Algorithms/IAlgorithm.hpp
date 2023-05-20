#pragma once
#include "..\stdafx.h"
#include "..\Utilities\DependencyInjection\IInjectable.hpp"
#include "..\Models\Configuration.hpp"

class IAlgorithm : public IInjectable
{
public:
	/// <summary> Call to load a specific configuration into this algorithm </summary>
	virtual void SetConfiguration(Configuration config) = 0;
};
