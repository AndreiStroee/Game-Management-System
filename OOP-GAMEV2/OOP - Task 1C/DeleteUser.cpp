#include "DeleteUser.h"

DeleteUser::DeleteUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


void DeleteUser::OutputOptions()
{
	for (int i = 0; i < app->listOfAccounts[0]->listOfUsers.length(); i++)
	{
		Option(i + 1, app->GetCurrentAccount()->listOfUsers[i]->GetUsername());
	}

}

bool DeleteUser::HandleChoice(char choice)
{
	int choiceAt = choice - '0';

	if (app->GetCurrentUser() == app->GetCurrentAccount()->listOfUsers[choiceAt - 1])
	{
		Line("You can not delete yourself");
	}
	else {
		app->GetCurrentAccount()->listOfUsers.deleteOne(app->GetCurrentAccount()->listOfUsers[choiceAt - 1]);
	}
	return false;
}