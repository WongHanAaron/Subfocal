#include "stdafx.h"
#include "AlgorithmFactoryBase.hpp"

std::shared_ptr<Algorithm> AlgorithmFactoryBase::Create(const std::string& algorithmKey, Configuration config)
{
	auto search = _algorithmToCreationMethod.find(algorithmKey);
	if (search != _algorithmToCreationMethod.end())
		return search->second.second();
	
	throw std::invalid_argument("Unable to create an algorithm from factory '" + GetComponentName() + "' from key '" + algorithmKey + "'");
}

void AlgorithmFactoryBase::Inject(DependencyProvider* provider)
{
	_dependencyProvider = provider->GetService<DependencyProvider>();

	for (auto& f : _algorithmTransientCreationMethod)
	{
		_dependencyProvider->AddTransientFactory(f);
	}
}

