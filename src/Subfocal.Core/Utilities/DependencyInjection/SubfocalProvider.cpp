#include "SubfocalProvider.hpp"

SubfocalProvider::SubfocalProvider()
{
	DependencyCollection::AddSingleton(std::make_shared<DateTimeProvider>());
}