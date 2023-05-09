#include "MainMenu.hpp"

std::string MainMenu::GetMenuName() { return "Main"; }

void MainMenu::WriteLine(std::string line)
{
	std::cout << line << std::endl;
}

std::string MainMenu::GetLine()
{
	std::string str;
	std::cin >> str;
	return str;
}