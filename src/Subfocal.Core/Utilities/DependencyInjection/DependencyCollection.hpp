#pragma once
#include <memory>
#include <vector>
#include <string>
#include "IInjectable.hpp"
#include "..\Logging\Logger.hpp"

/// <summary> The collection that can have dependencies registered to it and extracted from it </summary>
class DependencyCollection : public DependencyProvider
{
public:
	DependencyCollection();

	/// <summary> Adds this component to the dependency collection </summary>
	template<typename Injectable>
	void AddSingleton(std::shared_ptr<Injectable> component);

	template<typename Injectable>
	void AddTransient();

protected:
	std::shared_ptr<Logger> _logger;

	void Trace(const std::string& message);
	void Warn(const std::string& message);
	void Error(const std::string& message);

	void Inject(std::shared_ptr<IDependable> dependable);
};

