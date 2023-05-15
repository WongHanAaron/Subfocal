#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Environment/IDateTimeProvider.hpp";
#include "../../../src/Subfocal.Core/Utilities/DependencyInjection/SubfocalProvider.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(SubfocalProvider_Tests)
	{
	public:
		
		TEST_METHOD(SubfocalProvider_Creates_DateTimeProvider)
		{
			auto provider = std::make_shared<SubfocalProvider>();

			Assert::IsNotNull(provider.get(), L"Collection created should not be null");

			auto dateTimeProvider = provider->GetService<IDateTimeProvider>();

			Assert::IsNotNull(dateTimeProvider.get(), L"Date time provider should not be null");
		}
	};
}
