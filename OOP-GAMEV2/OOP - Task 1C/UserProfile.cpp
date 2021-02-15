#include "UserProfile.h"
#include "CreateUser.h"
#include "DeleteUser.h"


UserProfile::UserProfile(std::string& profileName, Application* app, User* user) : Menu(profileName, app), user(user)
{
	Paint();
}



void UserProfile::OutputOptions()
{
	std::string credits = to_string(user->getCredits());

	Line("Credits:" + credits);
	Option('I', "Buy 1 Credit");
	Option('O', "Buy 10 Credits");
	Option('P', "Buy 100 Credits");
	Line();

	Line("GAMES");
	for (int i = 0; i < user->getLibraryItems().size(); i++)
	{
		Option(i+1, user->getLibraryItems()[i]->GetGame().GetName()+Utils::formatTime(user->getLibraryItems()[i]->getTimePlayed()));
	}

	if (app->GetCurrentUser()->isAdmin())
	{
		Line();
		Line("ADMIN");
		Option('C', "Create user");
		Option('D', "Delete user");
	}
}

bool UserProfile::HandleChoice(char choice)
{

	int index = choice - '1';
	if (index >= 0 && index < user->getLibraryItems().size())
	{
		if (index >= 0 && index < user->getLibraryItems().size())
		{
			double newTime = Utils::addRandomNumber(user->getLibraryItems()[index]->getTimePlayed());
			user->getLibraryItems()[index]->setTimePlayed(newTime);
		}
	}

	switch (choice)
	{
	case 'C':
	{
		CreateUser CU("Create New User", app);
	}
	break;
	case 'D':
	{
		DeleteUser du("Delete User", app); 
		
	}
	break;
	case 'I':
	{
		user->addCredits(1);
	}
	break;
	case 'O':
	{
		user->addCredits(10);
	}
	break;
	case 'P':
	{
		user->addCredits(100);
	}
	//break;
	//case 'A':
	//{
	//	std::string gameNumber = Question("Which game do you want to add?");
	//	int index = stoi(gameNumber) - 1;

	//	if (Utils::gameInLibraryItems(user->getLibraryItems()[index]->GetGame().GetName(), &app->GetCurrentAccount()->listOfUsers[0]->getLibraryItems()))
	//	{
	//		Line("Game is already available to Guests");
	//	}
	//	else
	//	{
	//		app->GetCurrentAccount()->listOfUsers[0]->getLibraryItems().push_back(new LibraryItem(Date(), &user->getLibraryItems()[index]->GetGame(), 0));
	//	}
	//}
	//break;
	//case 'R':
	//{
	//	Line();
	//	std::string gameNumber = Question("Which game do you want to remove?");
	//	int index = stoi(gameNumber) - 1;

	//	if (Utils::gameInLibraryItems(user->getLibraryItems()[index]->GetGame().GetName(), &app->GetCurrentAccount()->listOfUsers[0]->getLibraryItems()))
	//	{
	//		app->GetCurrentAccount()->listOfUsers[0]->getLibraryItems().erase(app->GetCurrentAccount()->listOfUsers[0]->getLibraryItems().begin() + index);

	//		//remove game
	//	}
	//	else
	//	{
	//		Line("Game is not available to Guests, no need to remove.");
	//	}
	//}
	//case 'M':
	//{
	//	std::string gC = Question("What game do you want to play");
	//	int index = stoi(gC) - 1;
	//	if (index >= 0 && index < user->getLibraryItems().size())
	//	{
	//		double newTime = Utils::addRandomNumber(user->getLibraryItems()[index]->getTimePlayed());
	//		user->getLibraryItems()[index]->setTimePlayed(newTime);
	//	}
	//	Paint();
	//}
	//break;
	//case 'K':
	//{
		//std::string gC = Question("What game do you want to rate");
		//int index = stoi(gC) - 1;
		//if (index >= 0 && index < user->getLibraryItems().size())
		//{
		//	std::string gR = Question("Like (1) or Dislike (0)?");
		//	int rating = stoi(gR) - 1;
		//	user->getLibraryItems()[index]->setRating(rating);
		//}
		//Paint();
	//}
	break;
	}
	return false;
}