#pragma once

#include "Menu.h"
#include "StoreMenu.h"

class MainMenu : public Menu
{
public:
		MainMenu(const std::string& title, Application* application);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
};