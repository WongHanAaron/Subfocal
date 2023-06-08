#pragma once
#include "../Utilities/ConsoleMenu.hpp"
#include "../../../src/Subfocal.Core/Utilities/DependencyInjection/SubfocalProvider.hpp"

class BinaryCompositeMenu : public ConsoleMenu
{
public:
	BinaryCompositeMenu();

	void CrossFadeTest();

	void MultiResolutionSplineTest();

	virtual std::string GetMenuName() override;

	template <typename BinaryCompositeType>
	void RunFruitMergeTest(const std::string& algorithmName, Configuration configuration);

	std::tuple<cv::Mat, cv::Mat, cv::Mat> LoadFruitImages();
};
