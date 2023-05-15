#include "SubfocalProvider.hpp"

SubfocalProvider::SubfocalProvider()
{
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