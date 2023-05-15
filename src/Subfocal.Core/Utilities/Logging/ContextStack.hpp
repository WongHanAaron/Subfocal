#pragma once
#include "IContextStack.hpp"

/// <summary> The class that stores the logging contexts in a stack </summary>
class ContextStack : public IContextStack
{
	// Inherited via IContextStack
	virtual std::string GetComponentName() override;
};

