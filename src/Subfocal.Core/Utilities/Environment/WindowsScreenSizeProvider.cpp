#include "stdafx.h"
#include "WindowsScreenSizeProvider.hpp"

int WindowsScreenSizeProvider::GetWidth() 
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	auto width = desktop.right;
	return width;
}

int WindowsScreenSizeProvider::GetHeight() 
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	auto height = desktop.bottom;
	return height;
}

std::string WindowsScreenSizeProvider::GetComponentName()
{
	return "WindowsScreenSizeProvider";
}
