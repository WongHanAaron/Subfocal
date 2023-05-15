#include "DependencyCollection.hpp"

DependencyCollection::DependencyCollection() {}

template<typename Injectable>
void DependencyCollection::AddSingleton(std::shared_ptr<Injectable> component)
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

template<typename Injectable>
void DependencyCollection::AddTransient() 
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

void DependencyCollection::Trace(const std::string& message)
{
	if (_logger != nullptr) _logger->Trace(message);
}

void DependencyCollection::Warn(const std::string& message)
{
	if (_logger != nullptr) _logger->Warn(message);
}

void DependencyCollection::Error(const std::string& message)
{
	if (_logger != nullptr) _logger->Error(message);
}

void DependencyCollection::Inject(std::shared_ptr<IDependable> dependable)
{
	auto injectable = std::dynamic_pointer_cast<IInjectable>(dependable);
	if (injectable != nullptr)
	{
		injectable->Inject(this);
	}
}