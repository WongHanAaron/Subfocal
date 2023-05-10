#pragma once
#include "..\Utilities\ConsoleMenu.hpp"
#include "..\..\..\src\Subfocal.Core\Utilities\Image\Montage.hpp"

class MainMenu : public ConsoleMenu
{
public:

	MainMenu();

protected:
	std::string GetMenuName();

	void ReadAndShowImage();
};

