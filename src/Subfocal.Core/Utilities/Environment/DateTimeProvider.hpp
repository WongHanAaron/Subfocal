#pragma once
#include "IDateTimeProvider.hpp"

class DateTimeProvider : public IDateTimeProvider
{
public:

	std::time_t GetTimeNow();
};

