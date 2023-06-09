#include "stdafx.h"
#include "Pyramid.hpp"

std::vector<cv::Mat> Pyramid::GetGaussian(const cv::Mat image, int layers)
{
	std::vector<cv::Mat> returned;
	returned.push_back(image);

	cv::Mat currentImage = image;

	for (int i = 0; i < layers || layers < 0; i++)
	{
		auto size = currentImage.size();
		auto newWidth = (int) (size.width / 2.0f);
		auto newHeight = (int) (size.height / 2.0f);

		if (newWidth == size.width ||
			newHeight == size.height || 
			newWidth <= 0 ||
			newHeight <= 0)
		{
			return returned;
		}

		cv::Mat pyrDowned;
		cv::pyrDown(currentImage, pyrDowned);
		returned.push_back(pyrDowned);
		currentImage = pyrDowned;
	}

	return returned;
}

std::vector<cv::Mat> Pyramid::GetLaplacian(const cv::Mat image, int layers)
{
	return GetLaplacian(GetGaussian(image, layers));
}

std::vector<cv::Mat> Pyramid::GetLaplacian(const std::vector<cv::Mat> gaussianPyramid)
{
	std::vector<cv::Mat> returned;

	// Start with the smallest pyramid at the end
	returned.push_back(gaussianPyramid[gaussianPyramid.size() - 1]);

	for (int i = 1; i < gaussianPyramid.size(); i++)
	{
		int index = gaussianPyramid.size() - i - 1;

		auto current = gaussianPyramid[index];
		auto previous = gaussianPyramid[index + 1];
		
		cv::Mat upPyred;

		// Scale up the previous layer
		cv::pyrUp(previous, upPyred);

		// Match the size of the upscaled previous layer to the next gaussian layer
		upPyred = Resize::ToFit(upPyred, current.size(), ResizeMode::Crop);

		cv::Mat currentF, upPyredF;

		current.convertTo(currentF, CV_32F);
		upPyred.convertTo(upPyredF, CV_32F);

		auto difference = currentF - upPyredF;

		returned.push_back(difference);
	}

	std::reverse(returned.begin(), returned.end());

	return returned;
}

cv::Mat Pyramid::Up(cv::Mat input, int iterations, int borderType)
{
	cv::Mat returned = input;
	for (int i = 0; i < iterations; i++)
	{
		cv::pyrUp(returned, returned);
	}
	return returned;
}

cv::Mat Pyramid::Down(cv::Mat input, int iterations, int borderType)
{
	cv::Mat returned = input;
	for (int i = 0; i < iterations; i++)
	{
		cv::pyrDown(returned, returned);
	}
	return returned;
}
