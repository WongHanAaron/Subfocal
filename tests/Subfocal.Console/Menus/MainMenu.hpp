#pragma once
#include "..\Utilities\ConsoleMenu.hpp"

class MainMenu : public ConsoleMenu
{
protected:
	std::string GetMenuName();

	void WriteLine(std::string line);

	std::string GetLine();
};

