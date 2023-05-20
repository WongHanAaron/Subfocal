#pragma once
#include "IBinaryComposite.hpp"

/// <summary> Binary composite algorithm that </summary>
class CrossFade : public IBinaryComposite
{
public:
	// Inherited via IBinaryComposite
	virtual std::string GetComponentName() override;
	virtual void SetConfiguration(Configuration config) override;
	virtual cv::Mat Composite(const cv::Mat& image1, const cv::Mat& image2, const cv::Mat& mask1) override;
};

