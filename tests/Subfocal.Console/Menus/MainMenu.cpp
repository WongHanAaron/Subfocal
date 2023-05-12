#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	AddOption("R", "Read and show an image", std::bind(&MainMenu::ReadAndShowImage, this));
	AddOption("S", "Print out the screen resolution", std::bind(&MainMenu::GetScreenSize, this));
}

std::string MainMenu::GetMenuName() { return "Main"; }

void MainMenu::ReadAndShowImage()
{
	auto filepath = GetUserInput("Provide a file path to an image:");

	Montage::ReadAndShow(filepath);
}

void MainMenu::GetScreenSize()
{
	auto screenSizeProvider = std::make_shared<WindowsScreenSizeProvider>();
	auto height = screenSizeProvider->GetHeight();
	auto width = screenSizeProvider->GetWidth();

	WriteLine("Height: " + std::to_string(height));
	WriteLine("Width: " + std::to_string(width));
}