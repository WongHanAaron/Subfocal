#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\src\Subfocal.Core\Utilities\DependencyInjection\SubfocalProvider.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(Resize_Tests)
	{
	public:

		TEST_METHOD(SeamCarving_FindSeam_Tests)
		{
			auto provider = SubfocalProvider::Create();
			
			auto factory = provider->GetService<SubfocalAlgorithmFactory>();

			auto c = Configuration();
			c.Numeric["sobelwidth"] = 5;

			auto algorithm = factory->Create<SeamCarvingResize>("SeamCarvingResize", c);

			cv::Mat input = cv::Mat(20, 20, CV_32FC1, cv::Scalar(150.0));



			auto seam = algorithm->_findSeamInX(input);
		}
	};
}
