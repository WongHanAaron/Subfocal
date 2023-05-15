#pragma once
#include "..\DependencyInjection\IDependable.hpp"

/// <summary> Component that will access the screen size of the current desktop </summary>
class IScreenSizeProvider : IDependable
{
public:
	/// <summary> Get the width of the screen size </summary>
	virtual int GetWidth() = 0;
	/// <summary> Get the height of the screen size </summary>
	virtual int GetHeight() = 0;
};