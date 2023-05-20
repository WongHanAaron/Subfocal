#pragma once
#include "..\..\stdafx.h"

/// <summary> Base class used for generic configuration </summary>
class Configuration
{
public: 
	/// <summary> Map for numeric configurations </summary>
	std::map<std::string, double> Numeric;

	/// <summary> Map for string configuration </summary>
	std::map<std::string, std::string> String;

	/// <summary> 
	/// Clones the configuration object with all configuration fields whose key
	/// starts with the passed in prefix
	/// </summary>
	Configuration GetAllStartingWith(std::string prefix);
};

