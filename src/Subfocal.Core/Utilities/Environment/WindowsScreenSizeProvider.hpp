#pragma once
#include "IScreenSizeProvider.hpp"
#include "wtypes.h"
#include <iostream>

/// <summary>
/// Reference: https://stackoverflow.com/questions/8690619/how-to-get-screen-resolution-in-c#comment10808434_8690619
/// </summary>
class WindowsScreenSizeProvider : IScreenSizeProvider
{
public:
	int GetWidth();
	int GetHeight();
};

