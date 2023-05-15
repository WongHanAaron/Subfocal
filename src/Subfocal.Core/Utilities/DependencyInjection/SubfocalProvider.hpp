#pragma once
#include "DependencyCollection.hpp"
#include "..\Environment\DateTimeProvider.hpp"
#include "..\Environment\WindowsScreenSizeProvider.hpp"
#include "..\Logging\ContextStack.hpp"
#include "..\Logging\WindowImageLogger.hpp"

/// <summary> The provider class for all dependencies and injectables in the Subfocal project </summary>
class SubfocalProvider : public DependencyCollection
{
public:
	SubfocalProvider();

protected:

	void AddLoggingDependencies();
};

