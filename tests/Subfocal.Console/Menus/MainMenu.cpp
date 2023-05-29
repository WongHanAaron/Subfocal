#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	AddOption("R", "Read and show an image", std::bind(&MainMenu::ReadAndShowImage, this));
	AddOption("S", "Print out the screen resolution", std::bind(&MainMenu::GetScreenSize, this));
	AddOption("D", "Test the dependency injection", std::bind(&MainMenu::DependencyInjection_Tests, this));
	AddOption("B", "BinaryComposite Menu", std::bind(&MainMenu::PrintMenuOptions, this));
}

std::string MainMenu::GetMenuName() { return "Main"; }

void MainMenu::ReadAndShowImage()
{
	auto filepath = GetUserInput("Provide a file path to an image:");

}

void MainMenu::GetScreenSize()
{
	auto screenSizeProvider = std::make_shared<WindowsScreenSizeProvider>();
	auto height = screenSizeProvider->GetHeight();
	auto width = screenSizeProvider->GetWidth();

	WriteLine("Height: " + std::to_string(height));
	WriteLine("Width: " + std::to_string(width));
}

void MainMenu::DependencyInjection_Tests()
{
	auto provider = std::make_shared<SubfocalProvider>();
	auto logger = provider->GetService<Logger>();
	logger->Trace("Trace!");
	logger->Debug("Debug!");
	logger->Info("Info!");
	logger->Warn("Warn!");
	logger->Error("Error!");
}

void MainMenu::RunBinaryCompositeMenu()
{
	auto menu = std::make_shared<BinaryCompositeMenu>();

	menu->Run();
}
