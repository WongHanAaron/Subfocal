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

void MainMenu::WriteLine(const std::string& line)
{
	std::cout << line << std::endl;
}

std::string MainMenu::GetLine()
{
	std::string str;
	std::cin >> str;
	return str;
}