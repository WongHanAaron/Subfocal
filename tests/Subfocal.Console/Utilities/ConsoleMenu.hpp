#pragma once
#include <string>

class ConsoleMenu
{
public:
	void Run();

protected:
	/// <summary> Get the name of this implemented menu </summary>
	virtual std::string GetMenuName() = 0;

	/// <summary> </summary>
	virtual void WriteLine(std::string line) = 0;
};

