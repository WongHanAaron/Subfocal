#include "BinaryCompositeMenu.hpp"
#include "..\..\..\src\Subfocal.Core\Utilities\Image\Normalize.hpp"

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

	auto crossFade = factory->Create<CrossFade>("CrossFade", config);
	
	auto images = LoadFruitImages();

	auto blueberry = std::get<0>(images);
	auto blackberry = std::get<1>(images);
	auto mask = std::get<2>(images);

	// imageLogger->Log({ blueberry, blackberry, mask }, "images");
	auto kernel = crossFade->_getKernel(3);

	cv::Mat displayed;
	Normalize::Linear(kernel, 0, 255).convertTo(displayed, CV_8UC1);
	imageLogger->Log(displayed, "kernel");

	auto merged = crossFade->Composite(blueberry, blackberry, mask);

	imageLogger->Log(merged, "merged");
}

std::string BinaryCompositeMenu::GetMenuName()
{
	return "BinaryComposite";
}

std::tuple<cv::Mat, cv::Mat, cv::Mat> BinaryCompositeMenu::LoadFruitImages()
{
	auto rootDirectory = std::filesystem::current_path().parent_path().parent_path();
	auto blueberryPath = std::filesystem::path("images\\binarycomposite\\blueberry.png");
	auto blackberryPath = std::filesystem::path("images\\binarycomposite\\blackberry.png");
	auto maskPath = std::filesystem::path("images\\binarycomposite\\mask.png");

	auto blueberry = cv::imread((rootDirectory / blueberryPath).string());
	auto blackberry = cv::imread((rootDirectory / blackberryPath).string());
	auto mask = cv::imread((rootDirectory / maskPath).string());

	return std::make_tuple(blueberry, blackberry, mask);
}
