#pragma once
#include "..\..\stdafx.h"

template <typename DataType>
class Configurer
{
public:
	/// <summary> The default value for configurer </summary>
	DataType DefaultValue;

	/// <summary> The value setter method for this configurer </summary>
	std::function<void(DataType)> ValueSetter;

	/// <summary> A flag for if this configurer is required. Will throw an exception if this configuration did not exist </summary>
	bool IsRequired;
};