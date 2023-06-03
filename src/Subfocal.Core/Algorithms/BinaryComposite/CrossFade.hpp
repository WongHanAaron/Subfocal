#pragma once
#include "IBinaryComposite.hpp"
#include "..\..\Utilities\Image\Normalize.hpp"

/// <summary> Binary composite algorithm that </summary>
class CrossFade : public IBinaryComposite
{
public:
	CrossFade();

	virtual std::string GetComponentName() override;
	virtual cv::Mat Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask) override;

	/// <summary> Get the normalized kernel to cross fade the mask </summary>
	cv::Mat _getKernel(int width);

	/// <summary> The width of the cross fade applied </summary>
	int Width;
};

