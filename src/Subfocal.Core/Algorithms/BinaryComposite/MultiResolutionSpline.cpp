#include "stdafx.h"
#include "MultiResolutionSpline.hpp"

MultiResolutionSpline::MultiResolutionSpline()
{
	SetConfigurer("depth", [this](double val) -> void { this->Depth = val; }, -1, false);
	_setupStructuringMask(cv::MorphShapes::MORPH_ELLIPSE, 3);
}

std::string MultiResolutionSpline::GetComponentName()
{
	return "MultiResolutionSpline";
}

cv::Mat MultiResolutionSpline::Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask)
{
	auto image1Pyramid = Pyramid::GetGaussian(image1, Depth);
	auto image2Pyramid = Pyramid::GetGaussian(image2, Depth);
	auto maskPyramid = Pyramid::GetGaussian(mask, Depth);

	if (_logger->IsEnabled(LogLevel::Trace))
	{
		_logger->Trace(image1Pyramid, "Image1");
		_logger->Trace(image2Pyramid, "Image2");
		_logger->Trace(maskPyramid, "Mask");
	}

	auto image1Laplacian = Pyramid::GetLaplacian(image1Pyramid);
	auto image2Laplacian = Pyramid::GetLaplacian(image2Pyramid);

	if (_logger->IsEnabled(LogLevel::Trace))
	{
		_logger->Trace(image1Laplacian, "Image1");
		_logger->Trace(image2Laplacian, "Image2");
	}

	return _spline(image1Laplacian, image2Laplacian, maskPyramid);
}

cv::Mat MultiResolutionSpline::_spline(std::vector<cv::Mat> image1LaplacianPyramid, std::vector<cv::Mat> image2LaplacianPyramid, std::vector<cv::Mat> maskGaussianPyramid)
{
	auto first = image1LaplacianPyramid[0];
	auto layers = image1LaplacianPyramid.size();
	cv::Mat returned = cv::Mat(first.size(), first.type(), cv::Scalar(0));

	cv::Mat currentImage;

	for (int i = 1; i <= layers; i++)
	{
		int index = layers - i;

		auto image1 = image1LaplacianPyramid[index];
		auto image2 = image2LaplacianPyramid[index];
		auto mask = maskGaussianPyramid[index];

		cv::Mat thresholdedMask;
		cv::threshold(mask, thresholdedMask, 127, 255, cv::ThresholdTypes::THRESH_BINARY);

		auto maskEdge = _getMaskEdge(thresholdedMask);

		auto blendingEdge = _createBlendingImage(thresholdedMask, maskEdge);

		if (image1.channels() == 3 && blendingEdge.channels() != 3)
		{
			cv::cvtColor(blendingEdge, blendingEdge, cv::COLOR_GRAY2BGR);
		}

		auto size = image1.size();
		cv::Scalar one = image1.channels() == 3 ? cv::Scalar(1.0, 1.0, 1.0) : cv::Scalar(1.0);

		if (_logger->IsEnabled(LogLevel::Trace))
		{
			_logger->Trace({ image1, 
							 image2, 
							 mask, 
							 thresholdedMask, 
							 maskEdge,
							 blendingEdge * 255.0
							}, "Splice Layer " + std::to_string(index) + ". x: " + std::to_string(size.width) + " y: " + std::to_string(size.height));
		}

		cv::Mat image1F;
		cv::Mat image2F;

		image1.convertTo(image1F, CV_32F);
		image2.convertTo(image2F, CV_32F);

		cv::multiply(image1F, blendingEdge, image1F);
		cv::multiply(image2F, one - blendingEdge, image2F);

		cv::Mat merged = image1F + image2F;

		if (i == 1)
		{
			cv::pyrUp(merged, currentImage);
		}
		else
		{
			currentImage += merged;
			cv::pyrUp(currentImage, currentImage);
		}

		if (_logger->IsEnabled(LogLevel::Trace))
		{
			_logger->Trace({ 
					merged,
					currentImage
				}, "Merged Layer " + std::to_string(index) + ". x: " + std::to_string(size.width) + " y: " + std::to_string(size.height));
		}
	}

	cv::threshold(currentImage, currentImage, 255, 255, cv::ThresholdTypes::THRESH_TRUNC);

	currentImage.convertTo(returned, returned.type());

	_logger->Trace({ currentImage, returned }, "Returned Image");

	return returned;
}

cv::Mat MultiResolutionSpline::_getMaskEdge(cv::Mat thresholdedMask)
{
	cv::Mat dilated;
	cv::dilate(thresholdedMask, dilated, _maskStructuringElement);

	cv::Mat edge = dilated - thresholdedMask;

	/*if (_logger->IsEnabled(LogLevel::Trace))
	{
		_logger->Trace({ thresholdedMask, eroded, edge }, "_getMaskEdge: Original, Eroded, Edge. Width: " + std::to_string(thresholdedMask.cols) + " Height:" + std::to_string(thresholdedMask.rows));
	}*/

	return edge;
}

void MultiResolutionSpline::_setupStructuringMask(int shape, int size)
{
	_maskStructuringElement = cv::getStructuringElement(shape, cv::Size(size, size));
}

cv::Mat MultiResolutionSpline::_createBlendingImage(cv::Mat thresholdedMask, cv::Mat maskEdge)
{
	cv::Mat maskFloat;
	cv::Mat edgeFloat;

	thresholdedMask.convertTo(maskFloat, CV_32FC1);

	maskFloat = maskFloat / 255.0f;

	maskEdge.convertTo(edgeFloat, CV_32FC1);

	edgeFloat = edgeFloat / 255.0f * 0.5f;

	return maskFloat + edgeFloat;
}
