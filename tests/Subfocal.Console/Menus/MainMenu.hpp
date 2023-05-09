#pragma once
#include "..\Utilities\ConsoleMenu.hpp"

class MainMenu : public ConsoleMenu
{
public:

	MainMenu();

protected:
	std::string GetMenuName();

	void TestLog();
};

