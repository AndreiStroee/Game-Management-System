#include "LoginAccountMenu.h"

LoginAccountMenu::LoginAccountMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginAccountMenu::OutputOptions()
{
	for (int i = 0; i < app->listOfAccounts.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, app->listOfAccounts[i]->getEmail());
	}
}

bool LoginAccountMenu::HandleChoice(char choice)
{
	string password = Question("Please enter the password");
	int choiceAt = choice - '0';
	return app->LoginAccount(app->listOfAccounts[choiceAt - 1]->getEmail(), password);
}