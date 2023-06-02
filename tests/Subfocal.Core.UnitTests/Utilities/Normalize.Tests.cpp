#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Image/Normalize.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(Normalize_Tests)
	{
	public:
		TEST_METHOD(NormalizeLinear_CV_8UC1_Tests)
		{
			// 0: actualMinValue
			// 1: actualMaxValue
			// 2: minValue
			// 3: maxValue 
			std::vector<std::tuple<int, int, int, int>> tests;
			tests.push_back(std::make_tuple(10, 100, 0, 255));
			tests.push_back(std::make_tuple(50, 75, 0, 255));
			tests.push_back(std::make_tuple(0, 255, 100, 255));
			tests.push_back(std::make_tuple(0, 255, 100, 150));

			bool debug = false;

			for (auto test : tests)
			{
				auto actualMinValue = std::get<0>(test);
				auto actualMaxValue = std::get<1>(test);
				auto minValue = std::get<2>(test);
				auto maxValue = std::get<3>(test);

				auto input = cv::Mat(cv::Size(10, 10), CV_8UC1, cv::Scalar(actualMinValue));

				cv::rectangle(input, cv::Rect(2, 2, 6, 6), cv::Scalar(actualMaxValue));

				auto normalized = Normalize::Linear(input, minValue, maxValue);

				double minVal, maxVal;
				cv::Point minLoc, maxLoc;
				cv::minMaxLoc(normalized, &minVal, &maxVal, &minLoc, &maxLoc);

				Assert::AreEqual(minValue, (int)minVal);
				Assert::AreEqual(maxValue, (int)maxVal);
			}
		}

		TEST_METHOD(NormalizeLinear_CV_32F1_Tests)
		{
			// 0: actualMinValue
			// 1: actualMaxValue
			// 2: minValue
			// 3: maxValue 
			std::vector<std::tuple<double, double, double, double>> tests;
			tests.push_back(std::make_tuple(10.0, 100.0, 0.0, 255.0));
			tests.push_back(std::make_tuple(50.0, 75.0, 0, 255.0));
			tests.push_back(std::make_tuple(0, 255.0, 100.0, 255.0));
			tests.push_back(std::make_tuple(0, 255.0, 100.0, 150.0));
			tests.push_back(std::make_tuple(0, 255.0, 0.0, 1.0));
			tests.push_back(std::make_tuple(0, 1.0, 0.0, 255.0));

			bool debug = false;

			for (auto test : tests)
			{
				auto actualMinValue = std::get<0>(test);
				auto actualMaxValue = std::get<1>(test);
				auto minValue = std::get<2>(test);
				auto maxValue = std::get<3>(test);

				auto input = cv::Mat(cv::Size(10, 10), CV_32FC1, cv::Scalar(actualMinValue));

				cv::rectangle(input, cv::Rect(2, 2, 6, 6), cv::Scalar(actualMaxValue));

				auto normalized = Normalize::Linear(input, minValue, maxValue);

				double minVal, maxVal;
				cv::Point minLoc, maxLoc;
				cv::minMaxLoc(normalized, &minVal, &maxVal, &minLoc, &maxLoc);

				Assert::IsTrue(std::abs(minValue - minVal) < 0.001);
				Assert::IsTrue(std::abs(maxValue - maxVal) < 0.001);
			}
		}
	};
}
