#pragma once

#include "Menu.h"

class DeleteUser : public Menu
{
public:
	DeleteUser(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:

};
