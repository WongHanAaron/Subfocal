#include "pch.h"
#include "CppUnitTest.h"
#include "../../../src/Subfocal.Core/Utilities/Environment/IDateTimeProvider.hpp";
#include "../../../src/Subfocal.Core/Utilities/DependencyInjection/SubfocalProvider.hpp"
#include "../../../src/Subfocal.Core/Utilities/Logging/Logger.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(SubfocalProvider_Tests)
	{
	public:
		
		TEST_METHOD(SubfocalProvider_Creates_IDateTimeProvider)
		{
			auto provider = std::make_shared<SubfocalProvider>();

			Assert::IsNotNull(provider.get(), L"Collection created should not be null");

			auto dateTimeProvider = provider->GetService<IDateTimeProvider>();

			Assert::IsNotNull(dateTimeProvider.get(), L"Date time provider should not be null");
		}

		TEST_METHOD(SubfocalProvider_Creates_IScreenSizeProvider)
		{
			auto provider = std::make_shared<SubfocalProvider>();

			Assert::IsNotNull(provider.get(), L"Collection created should not be null");

			auto screensizeProvider = provider->GetService<IScreenSizeProvider>();

			Assert::IsNotNull(screensizeProvider.get(), L"Screen size provider should not be null");
		}

		TEST_METHOD(SubfocalProvider_Creates_IContextStack)
		{
			auto provider = std::make_shared<SubfocalProvider>();

			Assert::IsNotNull(provider.get(), L"Collection created should not be null");

			auto contextStack = provider->GetService<IContextStack>();

			Assert::IsNotNull(contextStack.get(), L"ContextStack should not be null");
		}

		TEST_METHOD(SubfocalProvider_Can_Get_IServiceProvider)
		{
			auto provider = std::make_shared<SubfocalProvider>();

			Assert::IsNotNull(provider.get(), L"Collection created should not be null");

			auto serviceProvider = provider->GetService<DependencyProvider>();

			Assert::IsNotNull(serviceProvider.get(), L"ContextStack should not be null");
		}
	};
}
