#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Image/Resize.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(Resize_Tests)
	{
	public:
		TEST_METHOD(ToFit_KeepAspectRatio_Tests)
		{
			// 0: input_width 
			// 1: input_height
			// 2: output_width
			// 3: output_height
			// 4: test_x_white
			// 5: test_y_white
			// 6: test_x_black
			// 7: test_y_black
			std::vector<std::tuple<int, int, int, int, int, int, int, int>> tests;
			tests.push_back(std::make_tuple(100, 100, 10, 10, 5, 5, -1, -1));
			tests.push_back(std::make_tuple(100, 100, 20, 20, 10, 10, -1, -1));
			tests.push_back(std::make_tuple(10, 10, 20, 20, 10, 10, -1, -1));
			tests.push_back(std::make_tuple(40, 20, 20, 20, 10, 10, 1, 1));

			bool debug = false;

			for (auto test : tests)
			{
				auto width = std::get<0>(test);
				auto height = std::get<1>(test);
				auto output_width = std::get<2>(test);
				auto output_height = std::get<3>(test);
				auto test_x_white = std::get<4>(test);
				auto test_y_white = std::get<5>(test);
				auto test_x_black = std::get<6>(test);
				auto test_y_black = std::get<7>(test);

				auto input = cv::Mat(cv::Size(width, height), CV_8UC1, cv::Scalar(255));

				auto outputSize = cv::Size(output_width, output_height);

				auto resized = Resize::ToFit(input, outputSize, true);

				Assert::AreEqual(outputSize.width, resized.size().width);
				Assert::AreEqual(outputSize.height, resized.size().height);

				if (debug) 
				{
					cv::imshow("test", input);
					cv::imshow("resized", resized);
					cv::waitKey(-1);
				}
				cv::destroyAllWindows();

				if (test_x_white >= 0 && test_y_white >= 0)
				{
					auto val = resized.at<uchar>(test_x_white, test_y_white);
					Assert::AreEqual((uchar)255, val);
				}

				if (test_x_black >= 0 && test_y_black >= 0)
				{
					auto val = resized.at<uchar>(test_x_black, test_y_black);
					Assert::AreEqual((uchar)0, val);
				}
			}
		}
	};
}
