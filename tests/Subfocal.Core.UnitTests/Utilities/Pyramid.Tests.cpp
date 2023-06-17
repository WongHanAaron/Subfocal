#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Image/Pyramid.hpp"
#include "../../../src/Subfocal.Core/Utilities/Image/Display.hpp"

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
	
		TEST_METHOD(Laplacian_Pyramid_Reconstructs)
		{
			bool debug = true;
			cv::Mat input = cv::Mat(100, 100, CV_8UC1, cv::Scalar(125));

			for (int i = 0; i < 10; i++)
			{
				cv::rectangle(input, cv::Rect(i * 10, 0, 5, 100), 0, -1);
			}
			
			auto pyramid = Pyramid::GetLaplacian(input);

			auto layers = pyramid.size();

			cv::Mat currentImage;

			for (int i = 1; i <= layers; i++)
			{
				int index = layers - i;

				auto image = pyramid[index];

				
				if (i == 1)
				{
					cv::pyrUp(image, currentImage);
				}
				else
				{
					currentImage += image;
					cv::pyrUp(currentImage, currentImage);
				}

				if (debug)
				{
					Display::Show(currentImage, std::to_string(i));
				}
			}
		}
	};
}
