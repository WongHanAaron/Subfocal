#include "stdafx.h"
#include "SubfocalProvider.hpp"

SubfocalProvider::SubfocalProvider()
{
	DependencyProvider::AddSingleton(std::make_shared<SubfocalProvider>(*this));
	AddLoggingDependencies();
}


void SubfocalProvider::AddLoggingDependencies()
{
	DependencyProvider::AddSingleton(std::make_shared<DateTimeProvider>());
	DependencyProvider::AddSingleton(std::make_shared<WindowsScreenSizeProvider>());
	DependencyProvider::AddSingleton(std::make_shared<ContextStack>());
	DependencyProvider::AddSingleton<WindowImageLogger>();
	DependencyProvider::AddSingleton<Logger>();
}

std::string SubfocalProvider::GetComponentName()
{
	return "SubfocalProvider";
}
