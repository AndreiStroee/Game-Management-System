#include "MainMenu.h"
#include "LoginMenu.h"
#include "UserProfile.h"
#include "LoginAccountMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
		Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn())
	{
		Option('S', "Browse Store");

		if (app->IsUserLoggedIn())
		{
			Option('P', "View Profile");
			Option('L', "Logout");
		}
		else
		{
			Option('L', "Login User");
			Option('A', "Logout Account");
		}
	}
	else
	{
		Option('L', "Login Account");
	}
}

bool MainMenu::HandleChoice(char choice)
{
		switch (choice)
		{
		case 'S':
		{
				StoreMenu sm("STORE", app);
		} break;
		case 'L':
		{
			if (app->IsAccountLoggedIn())
			{
				if (app->IsUserLoggedIn())
				{
					std::string answer = Question("Are you sure?");
					if (answer == "y" || answer == "Y")
					{
						app->LogoutUser();
					}
				}
				else
				{

					LoginMenu lm("LogIn Menu", app);
					
				}
			}
			else
			{
				LoginAccountMenu lam("Login Account Menu", app);
				
			}
		} break;
		case 'P':
		{
				if (app->IsUserLoggedIn())
				{
					UserProfile up(app->GetCurrentUser()->GetUsername() + "'s PROFILE", app, app->GetCurrentUser());
				}
		} break;
		case 'A':
		{
			app->LogoutAccount();
		}
		break;
		}

		return false;
}