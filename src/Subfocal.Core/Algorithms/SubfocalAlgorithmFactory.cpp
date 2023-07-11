#include "stdafx.h"
#include "SubfocalAlgorithmFactory.hpp"

SubfocalAlgorithmFactory::SubfocalAlgorithmFactory()
{
	AddAlgorithmFactory<BinaryCompositeFactory>();
	AddAlgorithmFactory<ResizeFactory>();
	AddAlgorithmFactory<SegmentationFactory>();
}

std::shared_ptr<Algorithm> SubfocalAlgorithmFactory::Create(const std::string& algorithmName, Configuration config)
{
	for (auto& f : _algorithmFactories)
	{
		if (f->HasAlgorithm(algorithmName))
			return f->Create(algorithmName, config);
	}

	throw std::invalid_argument("The SubfocalAlgorithm factory does not contain algorithm '" + algorithmName + "'");
}

void SubfocalAlgorithmFactory::Inject(DependencyProvider* provider)
{
	_dependencyProvider = provider->GetService<DependencyProvider>();

	for (auto& f : _algorithmFactories)
	{
		f->Inject(provider);
	}
}

bool SubfocalAlgorithmFactory::HasAlgorithm(const std::string& algorithmName)
{
	for (auto& f : _algorithmFactories)
	{
		if (f->HasAlgorithm(algorithmName))
			return true;
	}

	return false;
}

std::vector<std::string> SubfocalAlgorithmFactory::GetAvailableAlgorithms()
{
	std::vector<std::string> returned;

	for (auto& f : _algorithmFactories)
	{
		auto algorithms = f->GetAvailableAlgorithms();
		returned.insert(returned.end(), algorithms.begin(), algorithms.end());
	}

	return returned;
}

std::string SubfocalAlgorithmFactory::GetComponentName()
{
	return "SubfocalAlgorithmFactory";
}

template<typename AlgorithmFactoryType>
void SubfocalAlgorithmFactory::AddAlgorithmFactory() 
{
	_algorithmFactories.push_back(std::make_shared<AlgorithmFactoryType>());
}