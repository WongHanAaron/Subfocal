#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Image/Pyramid.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(Pyramid_Tests)
	{
	public:
		TEST_METHOD(GetGaussian_Tests)
		{
			// 0: input_width, 1: input_height, 2: input_layers, 3: expected_layers
			std::vector<std::tuple<int, int, int, int>> tests;
			tests.push_back(std::make_tuple(100, 100, 2, 3));
			tests.push_back(std::make_tuple(100, 100, -1, 8));

			for (auto test : tests)
			{
				auto input_width = std::get<0>(test);
				auto input_height = std::get<1>(test);
				auto input_layers = std::get<2>(test);
				auto expected_layers = std::get<3>(test);

				cv::Mat input = cv::Mat(input_height, input_width, CV_8UC1);

				auto pyramid = Pyramid::GetGaussian(input, input_layers);

				Assert::AreEqual(expected_layers, (int)pyramid.size());
			}
		}
	};
}
