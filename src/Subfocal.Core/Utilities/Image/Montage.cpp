#include "stdafx.h"
#include "Montage.hpp"

cv::Mat Montage::Make(std::initializer_list<cv::Mat> images, int dividerPixels, int maxWidth, int maxHeight, cv::Scalar dividerColor)
{
	auto maxImageSize = _getMaxImageSize(images);

	auto rowHeightPair = _fitCountToDimensions(images.size(), maxImageSize, maxWidth, maxHeight);

	return _makeProc(images, maxImageSize, rowHeightPair.first, rowHeightPair.second, dividerPixels, maxWidth, maxHeight);
}

std::tuple<int, int, int> Montage::_getMaxImageSize(std::initializer_list<cv::Mat> images)
{
	int maxHeight = 0;
	int maxWidth = 0;
	int maxChannels = 0;

	for (auto& i : images)
	{
		if (i.size().height > maxHeight)
			maxHeight = i.size().height;
		if (i.size().width > maxWidth)
			maxWidth = i.size().width;
		if (i.channels() > maxChannels)
			maxChannels = i.channels();
	}

	return std::make_tuple(maxWidth, maxHeight, maxChannels);
}

std::pair<int, int> Montage::_fitCountToDimensions(int count, std::tuple<int, int, int> maxImageSize, int maxWidth, int maxHeight)
{
	float equalSideLength = std::sqrt(count);
	float aspectRatio = (float)maxWidth / (float)maxHeight;

	int columns = (int)std::ceil((equalSideLength * aspectRatio) / std::sqrt(aspectRatio));
	int rows = (int)std::ceil((float)count / (float)columns);

	return std::make_pair(columns, rows);
}

cv::Mat Montage::_makeProc(std::initializer_list<cv::Mat> images, std::tuple<int, int, int> maxImageSize, int rows, int cols, int dividerPixels, int maxOutputWidth, int maxOutputHeight, cv::Scalar dividerColor)
{
	// Default to using the max to define the output size
	cv::Size outputSize = cv::Size(maxOutputWidth, maxOutputHeight);
	int channelCount = std::get<2>(maxImageSize);
	auto outputType = channelCount > 3 ? CV_8UC4 : 
				      channelCount > 1 ? CV_8UC3 : CV_8UC1;

	// If no max was defined, base the max on the size of the images fitting in that row
	if (maxOutputWidth <= 0 || maxOutputHeight <= 0)
	{
		// Calculate the size by getting the size of the largest image multipled by the number of images in that dimension adding the size of the dividers
		auto fullWidth = std::get<0>(maxImageSize) * cols + (cols - 1) * dividerPixels;
		auto fullHeight = std::get<1>(maxImageSize) * rows + (rows - 1) * dividerPixels;
		outputSize = cv::Size(fullWidth, fullHeight);
	}

	// Calculate the per image size
	auto perImageSize = cv::Size(std::floor(((float)outputSize.width - (cols - 1) * dividerPixels) / cols),
								 std::floor(((float)outputSize.height - (rows - 1) * dividerPixels) / rows));

	// Create the output image
	auto returned = cv::Mat(outputSize.height, outputSize.width, outputType, dividerColor);

	// Walk through the rows and columns and add the images onto each location
	int currentY = 0;
	for (int row = 0; row < rows; row++)
	{
		int currentX = 0;
		for (int col = 0; col < cols; col++)
		{
			
		}
	}

	return returned;
}