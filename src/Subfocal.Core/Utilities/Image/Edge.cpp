#include "stdafx.h"
#include "Edge.hpp"

std::tuple<cv::Mat, cv::Mat> Edge::Sobel(cv::Mat image, int outputDepth, int kernelSize, int borderType)
{
	if (image.channels() > 1)
	{
		cv::Mat* images = new cv::Mat[image.channels()];
		cv::Mat* xEdges = new cv::Mat[image.channels()];
		cv::Mat* yEdges = new cv::Mat[image.channels()];
		
		cv::split(image, images);

		for (int i = 0; i < image.channels(); i++)
		{
			auto singleImage = images[i];
			auto edges = SobelSingle(singleImage, outputDepth, kernelSize, borderType);
			xEdges[i] = std::get<0>(edges);
			yEdges[i] = std::get<1>(edges);
		}

		cv::Mat mergedX;
		cv::Mat mergedY;
		cv::merge(xEdges, image.channels(), mergedX);
		cv::merge(yEdges, image.channels(), mergedY);

		delete images;
		delete xEdges;
		delete yEdges;

		return std::make_tuple(mergedX, mergedY);
	}
	else
	{
		return SobelSingle(image, outputDepth, kernelSize, borderType);
	}
}

std::tuple<cv::Mat, cv::Mat> Edge::SobelSingle(cv::Mat image, int outputDepth, int kernelSize, int borderType)
{
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;

	cv::Sobel(image, grad_x, outputDepth, 1, 0, kernelSize, 1.0, 0.0, borderType);
	cv::Sobel(image, grad_y, outputDepth, 0, 1, kernelSize, 1.0, 0.0, borderType);

	return std::make_tuple(grad_x, grad_y);
}