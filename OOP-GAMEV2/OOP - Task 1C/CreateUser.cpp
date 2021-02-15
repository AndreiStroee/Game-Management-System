#include "CreateUser.h"

CreateUser::CreateUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

std::string username;
std::string password;

void CreateUser::OutputOptions()
{
	username = Question("Enter username");

	password = Question("Enter passowrd");

	Line("Are you sure you want to create a user? (y/n)");

}

bool CreateUser::HandleChoice(char choice)
{

	if (choice == 'y' || choice == 'Y')
	{
		app->GetCurrentAccount()->listOfUsers.addAtEnd(new Player(username, password, Date(), 0));
	}
	else return false;


	//should not hit
	return false;

}