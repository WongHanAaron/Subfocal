#include "stdafx.h"
#include "AlgorithmFactoryBase.hpp"

std::shared_ptr<Algorithm> AlgorithmFactoryBase::Create(const std::string& algorithmKey, Configuration config)
{
	return nullptr;
}

void AlgorithmFactoryBase::Inject(DependencyProvider* provider)
{
	_dependencyProvider = provider->GetService<DependencyProvider>();
}

