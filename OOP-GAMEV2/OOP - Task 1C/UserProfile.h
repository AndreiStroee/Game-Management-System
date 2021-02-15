#pragma once
#include "Menu.h"

class UserProfile : public Menu
{
public:
	UserProfile(std::string& profileName, Application* app, User* user);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	User* user;
};