#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Image/Montage.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(Montage_Tests)
	{
	public:
		TEST_METHOD(GetMaxImageSize_Tests)
		{
			auto size = Montage::_getMaxImageSize({cv::Mat(100, 20, CV_8UC1), cv::Mat(30, 40, CV_8UC1), cv::Mat(10, 10, CV_8UC1) });

			Assert::AreEqual(40, std::get<0>(size));
			Assert::AreEqual(100, std::get<1>(size));
		}

		TEST_METHOD(FitToDimensions_Tests)
		{
			// 0: counts, 1: maxWidth, 2: maxHeight, 3: expected columnns, 4: expected rows
			std::vector<std::tuple<int, int, int, int, int>> tests;
			tests.push_back(std::make_tuple(100, 40, 10, 20, 5));
			tests.push_back(std::make_tuple(100, 16, 8, 15, 7));

			for (auto test : tests)
			{
				auto counts = std::get<0>(test);
				auto maxWidth = std::get<1>(test);
				auto maxHeight = std::get<2>(test);
				auto expectedColumns = std::get<3>(test);
				auto expectedRows = std::get<4>(test);
				
				auto columnRowPair = Montage::_fitCountToDimensions(counts, std::make_tuple(1,1,1), maxWidth, maxHeight);
				
				auto columns = columnRowPair.first;
				auto rows = columnRowPair.second;

				Assert::AreEqual(expectedColumns, columns);
				Assert::AreEqual(expectedRows, rows);
				Assert::IsTrue(counts <= (columns * rows));
			}
		}
	};
}
