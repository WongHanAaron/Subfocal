#include "stdafx.h"
#include "DateTimeProvider.hpp"

std::time_t DateTimeProvider::GetTimeNow() 
{
	return std::time(0);
}

std::string DateTimeProvider::GetComponentName()
{
	return "DateTimeProvider";
}
