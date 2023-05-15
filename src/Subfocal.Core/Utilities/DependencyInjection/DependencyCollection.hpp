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
	template<typename Injectable> inline
	void AddSingleton(std::shared_ptr<Injectable> component)
	{
		auto cast = std::dynamic_pointer_cast<IDependable>(component);
		if (cast != nullptr)
		{
			_singletonDependencies.push_back(cast);
		}
		else
		{
			throw std::invalid_argument("Unable to inject dependency");
		}
	}


	template<typename Injectable> inline
	void AddTransient()
	{
		auto created = std::make_shared<Injectable>();
		auto cast = std::dynamic_pointer_cast<IDependable>(created);
		if (cast != nullptr)
		{
			_transientFactories.push_back(std::make_pair(created, []()
				{
					return std::make_shared<Injectable>();
				}));
		}
		else
		{
			throw std::invalid_argument("Unable to inject transient factory");
		}
	}

protected:
	std::shared_ptr<Logger> _logger;

	void Trace(const std::string& message);
	void Warn(const std::string& message);
	void Error(const std::string& message);

	void Inject(std::shared_ptr<IDependable> dependable);
};

