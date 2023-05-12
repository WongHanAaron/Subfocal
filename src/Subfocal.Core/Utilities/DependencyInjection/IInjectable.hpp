#pragma once
#include <string>

/// <summary> "Interface" that represents a class that can be injected using the dependency injection </summary>
class IInjectable
{
public:
	/// <summary> Gets the component name for this component. This should be name that the dependency is registered at </summary>
	virtual std::string GetComponentName() = 0;
};