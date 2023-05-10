#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <exception>
#include "..\..\..\src\Subfocal.Core\Utilities\String.hpp"

class ConsoleMenu
{
public:
	/// <summary> Run this console menu </summary>
	void Run();

	~ConsoleMenu();

protected:

	/// <summary> Contains the details for a class </summary>
	class MenuOption
	{
	public:
		/// <summary> The key for this menu option </summary>
		std::string Key;
		/// <summary> The description for this menu option </summary>
		std::string Description;
		/// <summary> The method that will be invoked with this menu option </summary>
		std::function<void()> Method;
	};

	///// <summary> The string invariant comparison operator </summary>
	//struct StringInvariantComparison {
	//	bool operator() (const std::string& lhs, const std::string& rhs) const {
	//		return stricmp(lhs.c_str(), rhs.c_str()) < 0;
	//	}
	//};

	/// <summary> Get the name of this implemented menu </summary>
	virtual std::string GetMenuName() = 0;

	/// <summary> Read a single line from the console </summary>
	virtual std::string GetLine();

	/// <summary> Write a single line to the output </summary>
	virtual void WriteLine(const std::string& line);

	/// <summary> Request the user input from the console </summary>
	std::string GetUserInput(const std::string& prompt);

	/// <summary> Print the menu options in the current menu </summary>
	void PrintMenuOptions();

	/// <summary> Try to run the option specified at the string </summary>
	void TryRunOption(const std::string& option);

	/// <summary> Add a menu option for this menu </summary>
	void AddOption(const std::string& key, const std::string& description, std::function<void()> method);

	/// <summary> The menu options for this menu </summary>
	std::map<std::string, std::shared_ptr<MenuOption>> _menuOptions;
};

