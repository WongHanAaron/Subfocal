#include "ConsoleMenu.hpp"

void ConsoleMenu::Run()
{
	WriteLine("Welcome to " + GetMenuName() + " Menu");
	bool repeat = true;
	
	while (repeat)
	{
		PrintMenuOptions();

		auto chosenOption = GetUserInput("Enter an option: ");

		if (chosenOption == "X" || chosenOption == "x")
		{
			repeat = false;
		}
		else
		{
			TryRunOption(chosenOption);
		}
	}
}

void ConsoleMenu::PrintMenuOptions()
{
	auto it = _menuOptions.begin();

	while (it != _menuOptions.end())
	{
		WriteLine("[" + it->second->Key + "] " + it->second->Description);
		++it;
	}

	WriteLine("[X] Exit this Menu");
}

void ConsoleMenu::TryRunOption(const std::string& option)
{
	if (_menuOptions.count(option) > 0)
	{
		try
		{
			_menuOptions[option]->Method();
			WriteLine("Command '" + option + "' completed");
		}
		catch (std::exception& e)
		{
			WriteLine("An error occured for option '" + option + "'. " + std::string(e.what()));
		}
	}
	else
	{
		WriteLine("No command exists for '" + option + "'");
	}
}

std::string ConsoleMenu::GetUserInput(const std::string& prompt)
{
	WriteLine(prompt);
	auto input = GetLine();
	WriteLine("Received '" + input + "'");
	return input;
}

void ConsoleMenu::AddOption(const std::string& key, const std::string& description, std::function<void()> method)
{
	auto option = std::make_shared<MenuOption>();
	option->Key = key;
	option->Description = description;
	option->Method = method;

	_menuOptions[key] = option;
}

void ConsoleMenu::WriteLine(const std::string& line)
{
	std::cout << line << std::endl;
}

std::string ConsoleMenu::GetLine()
{
	std::string str;
	std::cin >> str;
	return str;
}

ConsoleMenu::~ConsoleMenu()
{
	auto it = _menuOptions.begin();

	while (it != _menuOptions.end())
	{
		it->second = nullptr;
		++it;
	}

	_menuOptions.clear();
}