#pragma once
#include "..\..\stdafx.h"
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

		singleton = ConstructFromFactoryMethod<Dependable>(_singletonFactories);

		if (singleton != nullptr)
		{
			AddSingleton(singleton);
			return singleton;
		}

		auto transient = ConstructFromFactoryMethod<Dependable>(_transientFactories);
		
		if (transient != nullptr) return transient;

		throw std::invalid_argument("Unable to GetService for dependency");
	}

	/// <summary> Adds this component to the dependency collection </summary>
	template<typename Dependable> inline
		void AddSingleton(std::shared_ptr<Dependable> component)
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

	template<typename Dependable> inline
		void AddSingleton()
	{
		AddFactory<Dependable>(_singletonFactories);
	}

	template<typename Dependable> inline
		void AddTransient()
	{
		AddFactory<Dependable>(_transientFactories);
	}

protected:
	/// <summary> All the singleton created dependencies </summary>
	std::vector<std::shared_ptr<IDependable>> _singletonDependencies;
	
	/// <summary> All factory methods for creating singleton dependencies </summary>
	std::vector<std::pair<std::shared_ptr<IDependable>, std::function<std::shared_ptr<IDependable>(void)>>> _singletonFactories;

	/// <summary> All the factory methods for creating transient dependencies </summary>
	std::vector<std::pair<std::shared_ptr<IDependable>, std::function<std::shared_ptr<IDependable>(void)>>> _transientFactories;

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

	/// <summary> Create the dependable and inject its dependencies </summary>
	template<typename Dependable> inline std::shared_ptr<Dependable> ConstructFromFactoryMethod(const std::vector<std::pair<std::shared_ptr<IDependable>, std::function<std::shared_ptr<IDependable>(void)>>>& factoryMethods)
	{
		auto created = CreateFromFactoryMethod<Dependable>(factoryMethods);

		if (created == nullptr) return nullptr;

		auto dependable = std::dynamic_pointer_cast<IDependable>(created);

		if (dependable == nullptr) throw std::invalid_argument("Unable to create dependable from the successfully created service");

		Inject(dependable);

		return created;
	}

	/// <summary> Find a transient factory matching the type and create the transient </summary>
	template<typename Dependable> inline 
		std::shared_ptr<Dependable> CreateFromFactoryMethod(const std::vector<std::pair<std::shared_ptr<IDependable>, std::function<std::shared_ptr<IDependable>(void)>>>& factoryMethods)
	{
		for (auto& pair : factoryMethods)
		{
			auto castable = pair.first;
			auto factory = pair.second;
			auto cast = std::dynamic_pointer_cast<Dependable, IDependable>(castable);
			if (cast == nullptr) continue;
			auto created = factory();
			return std::dynamic_pointer_cast<Dependable, IDependable>(created);
		}

		return nullptr;
	}

	/// <summary> Add factoriy </summary>
	template<typename Dependable> inline void AddFactory(
		std::vector<std::pair<std::shared_ptr<IDependable>, std::function<std::shared_ptr<IDependable>(void)>>>& 
			factoryContainer)
	{
		auto created = std::make_shared<Dependable>();
		auto cast = std::dynamic_pointer_cast<IDependable>(created);
		if (cast != nullptr)
		{
			factoryContainer.push_back(std::make_pair(created, []()
				{
					return std::make_shared<Dependable>();
				}));
		}
		else
		{
			throw std::invalid_argument("Unable to inject factory");
		}
	}

	/// <summary> Inject the dependencies into the dependable </summary>
	virtual void Inject(std::shared_ptr<IDependable> dependable) = 0;
};

