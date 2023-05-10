#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class Montage
{
public:
	static cv::Mat ReadAndShow(const std::string& path);
};

