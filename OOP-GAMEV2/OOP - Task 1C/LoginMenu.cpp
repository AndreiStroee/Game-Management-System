#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginMenu::OutputOptions()
{
	for (int i = 0; i < app->listOfAccounts[0]->listOfUsers.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, app->GetCurrentAccount()->listOfUsers[i]->GetUsername());
	}
}

bool LoginMenu::HandleChoice(char choice)
{

	string password = Question("Please enter the password");
	int choiceAt = choice - '0';
	return app->LoginUser(app->GetCurrentAccount()->listOfUsers[choiceAt - 1]->GetUsername(), password);
}