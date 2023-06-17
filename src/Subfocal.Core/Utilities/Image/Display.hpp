#pragma once
#include "..\..\stdafx.h"

class Display
{
public:
	static void Show(cv::Mat image, std::string message = "Default", int keyWaitTime = -1);
};

