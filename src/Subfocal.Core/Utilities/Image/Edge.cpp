#include "stdafx.h"
#include "Edge.hpp"

std::tuple<cv::Mat, cv::Mat> Edge::Sobel(cv::Mat image, int outputDepth, int kernelSize, int borderType)
{
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;
	
	cv::Sobel(image, grad_x, outputDepth, 1, 0, kernelSize, 1.0, 0.0, borderType);
	cv::Sobel(image, grad_y, outputDepth, 0, 1, kernelSize, 1.0, 0.0, borderType);

	return std::make_tuple(grad_x, grad_y);
}
