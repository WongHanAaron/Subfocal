#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\..\src\Subfocal.Core\Models\Configuration\Configurable.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubfocalCoreUnitTests
{
	class ConfigurableTestClass : public Configurable
	{
	public:
		ConfigurableTestClass()
		{
			SetConfigurer("testProperty", [this](std::string val) -> void { this->TestProperty = val; }, "", false);
			SetConfigurer("value", [this](double val) -> void { this->Value = val; });
		}

		std::string TestProperty;
		double Value;

		// Inherited via Configurable
		virtual std::string GetComponentName() override
		{
			return "ConfigurableTestClass";
		}
	};

	TEST_CLASS(Configurable_Tests)
	{
	public:
		TEST_METHOD(SetConfiguration_Tests)
		{
			ConfigurableTestClass c;
			
			auto config = Configuration();
			config.String["testProperty"] = "something!";
			config.Numeric["value"] = 100;

			c.SetConfiguration(config);

			Assert::AreEqual(config.String["testProperty"], c.TestProperty);
			Assert::AreEqual(config.Numeric["value"], c.Value);
		}

		TEST_METHOD(Missing_Required_Throws_An_Exception)
		{
			bool threwException = false;
			try
			{
				ConfigurableTestClass c;

				auto config = Configuration();
				config.String["testProperty"] = "something!";

				c.SetConfiguration(config);
			}
			catch (std::exception& ex)
			{
				threwException = true;
			}

			Assert::AreEqual(true , threwException);

			threwException = false;

			try
			{
				ConfigurableTestClass c;

				auto config = Configuration();
				config.Numeric["value"] = 100;

				c.SetConfiguration(config);
			}
			catch (std::exception& ex)
			{
				threwException = true;
			}

			Assert::AreEqual(false, threwException);
		}
	};
}
