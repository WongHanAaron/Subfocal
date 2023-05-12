#include "DependencyCollection.hpp"

DependencyCollection::DependencyCollection() {}
DependencyCollection::DependencyCollection(std::shared_ptr<Logger> logger)
{
	_logger = logger;
}

template<typename Injectable>
std::shared_ptr<Injectable> DependencyCollection::Create()
{
	auto created = GetFirstSingleton<Injectable>();
	if (created != nullptr) return created;
	return nullptr;
}

template<typename Injectable>
std::shared_ptr<Injectable> DependencyCollection::GetFirstSingleton()
{
	for (auto& d : _singletonDependencies)
	{
		auto cast = std::dynamic_pointer_cast<Injectable, IInjectable>(d);
		if (cast != nullptr) return cast;
	}

	return nullptr;
}

void DependencyCollection::AddSingleton(std::shared_ptr<IInjectable> component)
{
	_singletonDependencies.push_back(component);
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