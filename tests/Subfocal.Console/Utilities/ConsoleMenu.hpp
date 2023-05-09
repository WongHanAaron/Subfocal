#pragma once
#include <iostream>
#include <string>

class ConsoleMenu
{
public:
	/// <summary>  </summary>
	void Run();

protected:
	/// <summary> Get the name of this implemented menu </summary>
	virtual std::string GetMenuName() = 0;

	/// <summary> Write a single line to the output </summary>
	virtual void WriteLine(std::string line) = 0;

	/// <summary> Read a single line from the console </summary>
	virtual std::string GetLine() = 0;

	void AddOption(std::string key);
};

