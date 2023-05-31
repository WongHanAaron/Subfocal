#pragma once
#include "..\..\stdafx.h"

class Montage
{
public:
	/// <summary> Montage together several images within the specific size </summary>
	static cv::Mat Make(std::initializer_list<cv::Mat> images, int dividerPixels = 0, int maxOutputWidth = -1, int maxOutputHeight = -1, cv::Scalar dividerColor = cv::Scalar(0,0,0));

	/// <summary> Gets the maximum image size and channel count. Returns (w, h, c) </summary>
	static std::tuple<int,int,int> _getMaxImageSize(std::initializer_list<cv::Mat> images);

	/// <summary> Get the rows and columns that would fit the counts of units within the aspect ratio of the max width and height. Assume a square if no max width or height is provided </summary>
	static std::pair<int, int> _fitCountToDimensions(int count, std::tuple<int, int, int> maxImageSize, int maxWidth = -1, int maxHeight = -1);

	/// <summary> Resize the input image and convert it to match the type required for the montage </summary>
	static cv::Mat _resizeAndConvert(cv::Mat image, cv::Size imageSize, int type);

	/// <summary> Actual method to create the montage given the rows, columns and  </summary>
	static cv::Mat _makeProc(std::initializer_list<cv::Mat> images, std::tuple<int, int, int> maxImageSize, int cols, int rows, int dividerPixels = 0, int maxOutputWidth = -1, int maxOutputHeight = -1, cv::Scalar dividerColor = cv::Scalar(0, 0, 0));
};

