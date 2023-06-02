#pragma once
class Normalize
{
public:
	static cv::Mat Linear(cv::Mat input, int min, int max);
	static cv::Mat Linear(cv::Mat input, double min, double max);
};

