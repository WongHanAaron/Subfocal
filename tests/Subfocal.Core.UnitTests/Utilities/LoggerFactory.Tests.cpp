#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\src\Subfocal.Core\Utilities\Logging\LoggerFactory.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(LoggerFactory_Tests)
	{
	public:
		
		TEST_METHOD(Default_Logger_Not_Null)
		{
			auto factory = std::make_shared<LoggerFactory>();

			Assert::IsNotNull(factory.get(), L"Factory created should not be null");

			auto logger = factory->Create();

			Assert::IsNotNull(logger.get(), L"Factory created should not be null");
		}
	};
}
