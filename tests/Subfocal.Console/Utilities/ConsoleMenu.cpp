#include "ConsoleMenu.hpp"

void ConsoleMenu::Run()
{
	WriteLine("Welcome to " + GetMenuName() + " Menu");
	WriteLine("Enter an input: ");
	auto input = GetLine();
	WriteLine("Received '" + input + "'");
}