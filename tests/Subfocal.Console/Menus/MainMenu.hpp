#pragma once
#include "..\Utilities\ConsoleMenu.hpp"
#include "..\..\..\src\Subfocal.Core\Utilities\Image\Montage.hpp"
#include "../../../src/Subfocal.Core/Utilities/Environment/WindowsScreenSizeProvider.hpp"
#include "../../../src/Subfocal.Core//Utilities/DependencyInjection/DependencyLoader.hpp"
#include "../../../src/Subfocal.Core/Utilities/DependencyInjection/SubfocalProvider.hpp"
#include "BinaryCompositeMenu.hpp"

class MainMenu : public ConsoleMenu
{
public:

	MainMenu();

protected:
	std::string GetMenuName();

	void ReadAndShowImage();

	void GetScreenSize();

	void DependencyInjection_Tests();

	void RunBinaryCompositeMenu();
};

