#pragma once
#include <memory>
#include <vector>
#include <string>
#include "IInjectable.hpp"
#include "..\Logging\Logger.hpp"
#include "..\Logging\LoggerFactory.hpp"

/// <summary> The collection that can have dependencies registered to it and extracted from it </summary>
class DependencyCollection
{
public:
	DependencyCollection();
	DependencyCollection(std::shared_ptr<Logger> logger);

	/// <summary> Grabs the first dynamically castable dependency of this type </summary>
	template<typename Injectable> inline
	std::shared_ptr<Injectable> Create() 
	{
		// Needs to be inline: https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
		auto created = GetFirstSingleton<Injectable>();
		if (created != nullptr) return created;
		return nullptr;
	}

	/// <summary> Adds this component to the dependency collection </summary>
	template<typename Injectable>
	void AddSingleton(std::shared_ptr<Injectable> component);

	inline int DependencyCount() { return _singletonDependencies.size(); }

protected:
	std::shared_ptr<Logger> _logger;
	std::vector<std::shared_ptr<IInjectable>> _singletonDependencies;

	void Trace(const std::string& message);
	void Warn(const std::string& message);
	void Error(const std::string& message);

	/// <summary> Grabs the first dynamically castable Singleton dependency of this type </summary>
	template<typename Injectable> inline
	std::shared_ptr<Injectable> GetFirstSingleton() 
	{
		// Needs to be inline: https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
		for (auto& d : _singletonDependencies)
		{
			auto cast = std::dynamic_pointer_cast<Injectable, IInjectable>(d);
			if (cast != nullptr) return cast;
		}

		return nullptr;
	}
};

