#pragma once

#include "Menu.h"

class CreateUser : public Menu
{
public:
	CreateUser(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	
};
