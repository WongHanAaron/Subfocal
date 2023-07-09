#pragma once
#include "ISegmentation.hpp"

class KnnSegmentation : public ISegmentation
{
public:


	// Inherited via ISegmentation
	virtual cv::Mat Segment(cv::Mat input) override;

	virtual std::string GetComponentName() override;

};

