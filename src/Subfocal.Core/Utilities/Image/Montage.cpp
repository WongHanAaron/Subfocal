#include "Montage.hpp"

cv::Mat Montage::ReadAndShow(const std::string& path)
{
	auto img = cv::imread(path);

	cv::imshow(path, img);

	cv::waitKey(0);

	cv::destroyWindow(path);

	return img;
}