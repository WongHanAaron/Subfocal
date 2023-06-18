#pragma once
#include "..\..\stdafx.h"
#include "DependencyLoader.hpp"
#include "..\Environment\DateTimeProvider.hpp"
#include "..\Environment\WindowsScreenSizeProvider.hpp"
#include "..\Logging\ContextStack.hpp"
#include "..\Logging\WindowImageLogger.hpp"
#include "..\..\Algorithms\SubfocalAlgorithmFactory.hpp"

/// <summary> The provider class for all dependencies and injectables in the Subfocal project </summary>
class SubfocalProvider : public DependencyLoader
{
public:
	SubfocalProvider();

	/// <summary> Perform post constructor initialization that needs to occur after the constructor </summary>
	void CompleteConstruction();

	inline static std::shared_ptr<SubfocalProvider> Create()
	{
		auto c = std::make_shared<SubfocalProvider>();
		c->CompleteConstruction();
		return c;
	}

	static std::shared_ptr<Logger> GetLogger();

	static std::shared_ptr<IImageLogger> GetImageLogger();

protected:

	void AddLoggingDependencies();

	void AddAlgorithmFactories();

	// Inherited via DependencyLoader
	virtual std::string GetComponentName() override;
};

