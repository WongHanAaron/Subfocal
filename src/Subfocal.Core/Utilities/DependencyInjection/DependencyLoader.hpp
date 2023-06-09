#pragma once
#include "..\..\stdafx.h"
#include <memory>
#include <vector>
#include <string>
#include "IInjectable.hpp"
#include "..\Logging\Logger.hpp"

/// <summary> The collection is used to inject dependencies into the injectables </summary>
class DependencyLoader : public DependencyProvider
{
public:
	DependencyLoader();

protected:

	/// <summary> Try to inject the  </summary>
	virtual void Inject(std::shared_ptr<IDependable> dependable) override;
};

