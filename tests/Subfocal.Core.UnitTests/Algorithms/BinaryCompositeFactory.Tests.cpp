#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\src\Subfocal.Core\Utilities\DependencyInjection\SubfocalProvider.hpp"
#include "..\..\..\src\Subfocal.Core\Algorithms\BinaryComposite\BinaryCompositeFactory.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(BinaryCompositeFactory_Tests)
	{
	public:

		TEST_METHOD(BinaryCompositeFactory_Creation_Tests)
		{
			auto provider = SubfocalProvider::Create();

			auto factory = provider->GetService<BinaryCompositeFactory>();

			Assert::IsNotNull(factory.get());

			auto c = Configuration();

			auto algorithm = factory->Create("CrossFade", c);

			Assert::IsNotNull(algorithm.get());

		}
	};
}
