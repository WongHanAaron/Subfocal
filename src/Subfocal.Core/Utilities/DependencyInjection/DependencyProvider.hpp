#pragma once
#include <memory>
#include <vector>
#include <stdexcept>
#include <functional>
#include "IDependable.hpp"

class DependencyProvider
{
public:
	/// <summary> Grabs the first dynamically castable dependency of this type </summary>
	template<typename Dependable> inline
		std::shared_ptr<Dependable> GetService()
	{
		// Needs to be inline: https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
		auto singleton = GetFirstSingleton<Dependable>();
		
		if (singleton != nullptr) return singleton;

		if (singleton == nullptr) throw std::invalid_argument("Unable to create dependency");

		auto dependable = std::dynamic_pointer_cast<IDependable, Dependable>(singleton);

		if (dependable == nullptr) throw std::invalid_argument("Unable to cast dependency as a dependable");

		Inject(dependable);

		return singleton;
	}

	inline int DependencyCount() { return _singletonDependencies.size(); }

protected:

	std::vector<std::shared_ptr<IDependable>> _singletonDependencies;
	std::vector < std::pair<std::shared_ptr<IDependable>, std::function<std::shared_ptr<IDependable>(void)>>> _transientFactories;

	/// <summary> Grabs the first dynamically castable Singleton dependency of this type </summary>
	template<typename Dependable> inline
		std::shared_ptr<Dependable> GetFirstSingleton()
	{
		// Needs to be inline: https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
		for (auto& d : _singletonDependencies)
		{
			auto cast = std::dynamic_pointer_cast<Dependable, IDependable>(d);
			if (cast != nullptr) return cast;
		}

		return nullptr;
	}

	template<typename Dependable> inline 
		std::function<std::shared_ptr<IDependable>(void)> GetFirstFactory()
	{

	}

	/// <summary> Inject the dependencies into the dependable </summary>
	virtual void Inject(std::shared_ptr<IDependable> dependable) = 0;
};

