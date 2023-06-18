#include "stdafx.h"
#include "SubfocalProvider.hpp"

SubfocalProvider::SubfocalProvider()
{
	AddLoggingDependencies();
	AddAlgorithmFactories();
}

void SubfocalProvider::CompleteConstruction()
{
	DependencyProvider::AddSingleton(shared_from_base<SubfocalProvider>());
}

std::shared_ptr<Logger> SubfocalProvider::GetLogger()
{
	auto provider = SubfocalProvider::Create();
	return provider->GetService<Logger>();
}

std::shared_ptr<IImageLogger> SubfocalProvider::GetImageLogger()
{
	auto provider = SubfocalProvider::Create();
	return provider->GetService<IImageLogger>();
}

void SubfocalProvider::AddLoggingDependencies()
{
	DependencyProvider::AddSingleton(std::make_shared<DateTimeProvider>());
	DependencyProvider::AddSingleton(std::make_shared<WindowsScreenSizeProvider>());
	DependencyProvider::AddSingleton(std::make_shared<ContextStack>());
	DependencyProvider::AddSingleton<WindowImageLogger>();
	DependencyProvider::AddSingleton<Logger>();
}

void SubfocalProvider::AddAlgorithmFactories()
{
	DependencyProvider::AddSingleton<SubfocalAlgorithmFactory>();
}

std::string SubfocalProvider::GetComponentName()
{
	return "SubfocalProvider";
}
