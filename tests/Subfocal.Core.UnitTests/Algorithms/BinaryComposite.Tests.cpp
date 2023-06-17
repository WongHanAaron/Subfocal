#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\src\Subfocal.Core\Utilities\DependencyInjection\SubfocalProvider.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(BinaryComposite_Tests)
	{
	public:

		TEST_METHOD(CrossFade_Tests)
		{
			auto provider = SubfocalProvider::Create();

			auto factory = provider->GetService<SubfocalAlgorithmFactory>();

			auto c = Configuration();

			auto algorithm = factory->Create<CrossFade>("CrossFade", c);

			cv::Mat img1 = cv::Mat(cv::Size(100, 100), CV_8UC1, cv::Scalar(0));
			cv::Mat img2 = cv::Mat(cv::Size(100, 100), CV_8UC1, cv::Scalar(255));
			cv::Mat mask = cv::Mat(cv::Size(100, 100), CV_8UC1, cv::Scalar(0));
			cv::rectangle(mask, cv::Rect(0, 0, 50, 100), cv::Scalar(255), -1);

			auto composite = algorithm->Composite(img1, img2, mask);
		}
	};
}
