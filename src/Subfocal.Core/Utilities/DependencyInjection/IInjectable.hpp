#pragma once
#include "..\..\stdafx.h"
#include "IDependable.hpp"
#include "DependencyProvider.hpp"

/// <summary> Represents a class that can be injected into </summary>
class IInjectable : public IDependable
{
public:
	/// <summary> Inject all dependencies through the dependency provider </summary>
	virtual void Inject(DependencyProvider* provider) { }
};