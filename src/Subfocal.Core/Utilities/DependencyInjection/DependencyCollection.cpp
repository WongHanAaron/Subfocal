#include "DependencyCollection.hpp"

DependencyCollection::DependencyCollection() {}

void DependencyCollection::Inject(std::shared_ptr<IDependable> dependable)
{
	auto injectable = std::dynamic_pointer_cast<IInjectable>(dependable);
	if (injectable != nullptr)
	{
		injectable->Inject(this);
	}
}