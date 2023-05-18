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

cv::Mat Montage::_resizeAndConvert(cv::Mat image, cv::Size imageSize, int type)
{
	auto inputType = image.channels() > 3 ? CV_8UC4 :
					  image.channels() > 1 ? CV_8UC3 : CV_8UC1;

	if (type == type) return image;

	cv::Mat result;

	if (inputType == CV_8UC1)
	{
		if (type == CV_8UC3)
		{
			cv::cvtColor(image, result, cv::COLOR_GRAY2BGR);
			return result;
		}
		else if (type == CV_8UC4)
		{
			cv::cvtColor(image, result, cv::COLOR_GRAY2BGRA);
			return result;
		}
	}

	throw std::invalid_argument("Unable to cast type of " + std::to_string(inputType) + " to " + std::to_string(type));
}

cv::Mat Montage::_makeProc(std::initializer_list<cv::Mat> images_initializer, std::tuple<int, int, int> maxImageSize, int rows, int cols, int dividerPixels, int maxOutputWidth, int maxOutputHeight, cv::Scalar dividerColor)
{
	// Default to using the max to define the output size
	auto images = std::vector<cv::Mat>(images_initializer);
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
			auto imageIndex = row * cols + col;
			if (imageIndex >= images_initializer.size()) continue;
			auto image = images[imageIndex];

			auto resized = _resizeAndConvert(image, perImageSize, outputType);

			returned(cv::Rect(currentX, currentY, perImageSize.width, perImageSize.height)) = resized;
			
			currentX += (perImageSize.width + dividerPixels);
		}

		currentY += (perImageSize.height + dividerPixels);
	}

	return returned;
}