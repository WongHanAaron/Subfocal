#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\src\Subfocal.Core\Utilities\DependencyInjection\DependencyCollection.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	TEST_CLASS(DependencyCollection_Tests)
	{
	public:
		
		TEST_METHOD(Default_Logger_Not_Null)
		{
			auto collection = std::make_shared<DependencyCollection>();

			Assert::IsNotNull(collection.get(), L"Collection created should not be null");
			Assert::AreEqual(0, collection->DependencyCount(), L"Collection created should not be null");
		}
	};
}
