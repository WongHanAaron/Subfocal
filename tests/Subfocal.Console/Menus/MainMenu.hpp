#pragma once
#include "..\Utilities\ConsoleMenu.hpp"
#include "..\..\..\src\Subfocal.Core\Utilities\Image\Montage.hpp"
#include "../../../src/Subfocal.Core/Utilities/Environment/WindowsScreenSizeProvider.hpp"

class MainMenu : public ConsoleMenu
{
public:

	MainMenu();

protected:
	std::string GetMenuName();

	void ReadAndShowImage();

	void GetScreenSize();
};

