#pragma once
#include <ctime>
#include "..\DependencyInjection\IDependable.hpp"

class IDateTimeProvider : public IDependable
{
public:

	/// <summary> Get the current time </summary>
	virtual std::time_t GetTimeNow() = 0;
};