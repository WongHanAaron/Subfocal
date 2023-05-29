#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\src\Subfocal.Core\Utilities\DependencyInjection\SubfocalProvider.hpp"
#include "..\..\..\src\Subfocal.Core\Algorithms\BinaryComposite\BinaryCompositeFactory.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(SubfocalAlgorithmFactory_Tests)
	{
	public:

		TEST_METHOD(SubfocalAlgorithmFactory_Creation_Tests)
		{
			auto provider = SubfocalProvider::Create();

			auto factory = provider->GetService<SubfocalAlgorithmFactory>();

			Assert::IsNotNull(factory.get());

			auto c = Configuration();

			auto algorithm = factory->Create("CrossFade", c);

			Assert::IsNotNull(algorithm.get());

			auto typedAlgorithm = factory->Create<CrossFade>("CrossFade", c);

			Assert::IsNotNull(typedAlgorithm.get());
		}
	};
}
