#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	AddOption("T", "test", std::bind(&MainMenu::TestLog, this));
}

std::string MainMenu::GetMenuName() { return "Main"; }

void MainMenu::TestLog()
{
	WriteLine("I am in the test log!!!");
}