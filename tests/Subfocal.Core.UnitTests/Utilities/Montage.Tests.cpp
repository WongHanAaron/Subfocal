#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Image/Montage.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(SubfocalProvider_Tests)
	{
	public:

		TEST_METHOD(GetMaxImageSize_Tests)
		{
			auto size = Montage::_getMaxImageSize({cv::Mat(100, 20, CV_8UC1), cv::Mat(30, 40, CV_8UC1), cv::Mat(10, 10, CV_8UC1) });

			Assert::AreEqual(100, size.height);
			Assert::AreEqual(40, size.width);
		}
	};
}
