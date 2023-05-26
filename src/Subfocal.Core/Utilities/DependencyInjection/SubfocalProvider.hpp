#pragma once
#include "..\..\stdafx.h"
#include "DependencyCollection.hpp"
#include "..\Environment\DateTimeProvider.hpp"
#include "..\Environment\WindowsScreenSizeProvider.hpp"
#include "..\Logging\ContextStack.hpp"
#include "..\Logging\WindowImageLogger.hpp"
#include "..\..\Algorithms\BinaryComposite\BinaryCompositeFactory.hpp"

/// <summary> The provider class for all dependencies and injectables in the Subfocal project </summary>
class SubfocalProvider : public DependencyCollection
{
public:
	SubfocalProvider();

protected:

	void AddLoggingDependencies();

	void AddAlgorithmFactories();

	// Inherited via DependencyCollection
	virtual std::string GetComponentName() override;
};

