#pragma once
#include "DependencyCollection.hpp"
#include "..\Environment\DateTimeProvider.hpp"
#include "..\Environment\WindowsScreenSizeProvider.hpp"

/// <summary> The provider class for all dependencies and injectables in the Subfocal project </summary>
class SubfocalProvider : public DependencyCollection
{
public:
	SubfocalProvider();

};

