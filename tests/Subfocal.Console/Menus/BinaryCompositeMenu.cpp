#include "BinaryCompositeMenu.hpp"

BinaryCompositeMenu::BinaryCompositeMenu()
{
	AddOption("C", "CrossFade test", std::bind(&BinaryCompositeMenu::CrossFadeTest, this));
}

void BinaryCompositeMenu::CrossFadeTest()
{
	auto provider = SubfocalProvider::Create();

	auto factory = provider->GetService<SubfocalAlgorithmFactory>();
	auto imageLogger = provider->GetService<IImageLogger>();

	auto config = Configuration();
	config.Numeric["width"] = 10;

	auto crossFade = factory->Create("CrossFade", config);
	
	auto rootDirectory = std::filesystem::current_path().parent_path().parent_path();
	auto blueberryPath = std::filesystem::path("images\\binarycomposite\\blueberry.png");
	auto blackberryPath = std::filesystem::path("images\\binarycomposite\\blackberry.png");
	auto maskPath = std::filesystem::path("images\\binarycomposite\\mask.png");

	WriteLine("Current Directory is: " + rootDirectory.string());

	auto blueberry = cv::imread((rootDirectory / blueberryPath).string());
	auto blackberry = cv::imread((rootDirectory / blackberryPath).string());
	auto mask = cv::imread((rootDirectory / maskPath).string());

	imageLogger->Log({ blueberry, blackberry, mask }, "images");
}

std::string BinaryCompositeMenu::GetMenuName()
{
	return "BinaryComposite";
}
