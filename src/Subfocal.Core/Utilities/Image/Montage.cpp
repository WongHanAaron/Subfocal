#include "stdafx.h"
#include "Montage.hpp"

cv::Mat Montage::Make(std::initializer_list<cv::Mat> images, double dividerPercentage, int maxWidth, int maxHeight)
{
	auto maxImageSize = _getMaxImageSize(images);

	auto rowHeightPair = _fitCountToDimensions(images.size(), maxImageSize, maxWidth, maxHeight);

	return _makeProc(images, rowHeightPair.first, rowHeightPair.second, dividerPercentage, maxWidth, maxHeight);
}

cv::Size Montage::_getMaxImageSize(std::initializer_list<cv::Mat> images)
{
	int maxHeight = 0;
	int maxWidth = 0;

	for (auto& i : images)
	{
		if (i.size().height > maxHeight)
			maxHeight = i.size().height;
		if (i.size().width > maxWidth)
			maxWidth = i.size().width;
	}

	return cv::Size(maxWidth, maxHeight);
}

std::pair<int, int> Montage::_fitCountToDimensions(int count, cv::Size maxImageSize, int maxWidth, int maxHeight)
{
	float equalSideLength = std::sqrt(count);
	float aspectRatio = (float)maxWidth / (float)maxHeight;

	int columns = (int)std::ceil((equalSideLength * aspectRatio) / std::sqrt(aspectRatio));
	int rows = (int)std::ceil((float)count / (float)columns);

	return std::make_pair(columns, rows);
}

cv::Mat Montage::_makeProc(std::initializer_list<cv::Mat> images, int rows, int cols, double dividerPercentage, int maxOutputWidth, int maxOutputHeight) 
{

	return cv::Mat();
}