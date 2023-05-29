#include "BinaryCompositeMenu.hpp"

BinaryCompositeMenu::BinaryCompositeMenu()
{
	AddOption("C", "CrossFade test", std::bind(&BinaryCompositeMenu::CrossFadeTest, this));
}

void BinaryCompositeMenu::CrossFadeTest()
{
	auto provider = SubfocalProvider::Create();

	auto factory = provider->GetService<SubfocalAlgorithmFactory>();

	auto config = Configuration();
	config.Numeric["width"] = 10;

	auto crossFade = factory->Create("CrossFade", config);


}
