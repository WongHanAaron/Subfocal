#include "stdafx.h"
#include "DependencyLoader.hpp"

DependencyLoader::DependencyLoader() {}

void DependencyLoader::Inject(std::shared_ptr<IDependable> dependable)
{
	auto injectable = std::dynamic_pointer_cast<IInjectable>(dependable);
	if (injectable != nullptr)
	{
		injectable->Inject(this);
	}
}