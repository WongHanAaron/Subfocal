#include "stdafx.h"
#include "KnnSegmentation.hpp"

// Reference: https://www.kdnuggets.com/2019/08/introduction-image-segmentation-k-means-clustering.html
cv::Mat KnnSegmentation::Segment(cv::Mat input)
{
    // Reshape into a vector
    cv::Mat vector = input.reshape(0, input.rows * input.cols);

    // Convert to float
    cv::Mat vectorF;
    vector.convertTo(vectorF, CV_32FC1);

    // cv::kmeans();

    return cv::Mat();
}

std::string KnnSegmentation::GetComponentName()
{
    return "KnnSegmentation";
}
