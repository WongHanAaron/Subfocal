#include "DateTimeProvider.hpp"

std::time_t DateTimeProvider::GetTimeNow() 
{
	return std::time(0);
}