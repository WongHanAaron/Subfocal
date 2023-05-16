#pragma once
#include "..\..\stdafx.h"
#include "IScreenSizeProvider.hpp"
#include "wtypes.h"

/// <summary>
/// Reference: https://stackoverflow.com/questions/8690619/how-to-get-screen-resolution-in-c#comment10808434_8690619
/// </summary>
class WindowsScreenSizeProvider : public IScreenSizeProvider
{
public:
	int GetWidth();
	int GetHeight();

	virtual std::string GetComponentName() override;
};

