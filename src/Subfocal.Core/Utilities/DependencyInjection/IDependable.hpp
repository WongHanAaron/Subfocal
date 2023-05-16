#pragma once
#include "..\..\stdafx.h"
#include <string>

/// <summary> "Interface" that represents a class that can be depended on by others and injected into using the dependency injection </summary>
class IDependable
{
public:
	/// <summary> Gets the component name for this component. This should be name that the dependency is registered at </summary>
	virtual std::string GetComponentName() = 0;
};