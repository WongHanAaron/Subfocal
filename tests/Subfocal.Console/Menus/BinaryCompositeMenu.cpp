#include "BinaryCompositeMenu.hpp"
#include "..\..\..\src\Subfocal.Core\Utilities\Image\Normalize.hpp"

BinaryCompositeMenu::BinaryCompositeMenu()
{
	AddOption("C", "CrossFade Test", std::bind(&BinaryCompositeMenu::CrossFadeTest, this));
	AddOption("M", "MultiResolution Spline Test", std::bind(&BinaryCompositeMenu::MultiResolutionSplineTest, this));
}

void BinaryCompositeMenu::CrossFadeTest()
{
	auto config = Configuration();
	config.Numeric["width"] = 100;

	RunFruitMergeTest<CrossFade>("CrossFade", config);
}

void BinaryCompositeMenu::MultiResolutionSplineTest()
{
	auto config = Configuration();
	config.Numeric["depth"] = -1;

	RunFruitMergeTest<MultiResolutionSpline>("MultiResolutionSpline", config);
}

std::string BinaryCompositeMenu::GetMenuName()
{
	return "BinaryComposite";
}

template<typename BinaryCompositeType>
void BinaryCompositeMenu::RunFruitMergeTest(const std::string& algorithmName, Configuration configuration)
{
	auto provider = SubfocalProvider::Create();

	auto factory = provider->GetService<SubfocalAlgorithmFactory>();
	auto imageLogger = provider->GetService<IImageLogger>();


	auto logger = provider->GetService<Logger>();
	logger->LogLevel = LogLevel::Trace;

	auto crossFade = factory->Create<BinaryCompositeType>(algorithmName, configuration);

	auto images = LoadFruitImages();

	auto blueberry = std::get<0>(images);
	auto blackberry = std::get<1>(images);
	auto mask = std::get<2>(images);

	auto merged = crossFade->Composite(blueberry, blackberry, mask);

	imageLogger->Log(merged, "merged");
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
