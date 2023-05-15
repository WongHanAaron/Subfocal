#include "DependencyCollection.hpp"

DependencyCollection::DependencyCollection() {}

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