#pragma once
#include <ctime>

class IDateTimeProvider
{
public:

	/// <summary> Get the current time </summary>
	virtual std::time_t GetTimeNow() = 0;
};