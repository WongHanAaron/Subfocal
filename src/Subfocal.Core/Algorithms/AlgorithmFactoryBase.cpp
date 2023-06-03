#include "stdafx.h"
#include "AlgorithmFactoryBase.hpp"

std::shared_ptr<Algorithm> AlgorithmFactoryBase::Create(const std::string& algorithmKey, Configuration config)
{
	auto search = _algorithmToCreationMethod.find(algorithmKey);
	if (search != _algorithmToCreationMethod.end())
	{
		auto created = search->second.second();
		created->SetConfiguration(config);
		return created;
	}
	
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

bool AlgorithmFactoryBase::HasAlgorithm(const std::string& algorithmName)
{
	auto search = _algorithmToCreationMethod.find(algorithmName);
	return search != _algorithmToCreationMethod.end();
}

std::vector<std::string> AlgorithmFactoryBase::GetAvailableAlgorithms()
{
	auto returned = std::vector<std::string>();

	for (auto& a : _algorithmToCreationMethod)
	{
		returned.push_back(a.first);
	}

	return returned;
}

