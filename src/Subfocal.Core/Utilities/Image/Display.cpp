#include "stdafx.h"
#include "Display.hpp"

void Display::Show(cv::Mat image, std::string message, int keyWaitTime)
{
	cv::imshow(message, image);
	cv::waitKey(keyWaitTime);
	cv::destroyWindow(message);
}
