#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	AddOption("R", "Read and show an image", std::bind(&MainMenu::ReadAndShowImage, this));
}

std::string MainMenu::GetMenuName() { return "Main"; }

void MainMenu::ReadAndShowImage()
{
	auto filepath = GetUserInput("Provide a file path to an image:");

	Montage::ReadAndShow(filepath);
}