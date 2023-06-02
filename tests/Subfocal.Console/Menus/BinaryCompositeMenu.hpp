#pragma once
#include "../Utilities/ConsoleMenu.hpp"
#include "../../../src/Subfocal.Core/Utilities/DependencyInjection/SubfocalProvider.hpp"

class BinaryCompositeMenu : public ConsoleMenu
{
public:
	BinaryCompositeMenu();

	void CrossFadeTest();

	virtual std::string GetMenuName() override;

	std::tuple<cv::Mat, cv::Mat, cv::Mat> LoadFruitImages();
};

