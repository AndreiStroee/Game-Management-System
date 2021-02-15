#include "GameMenu.h"

GameMenu::GameMenu(const std::string& title, Application* app, Game* game) : Menu(Utils::upperCaseRecursive(title), app), game(game)
{

	Paint();
	//printGameDetails();
}


void GameMenu::OutputOptions()
{
	Line(game->GetDescription());

	string ageRating = to_string(game->GetAgeRating());
	Line("Age Rating: " + ageRating);
	string price = to_string(("%.2f", game->GetCost() / 100));
	Line("Price: $" + price);
	Line();
	Line("Game Rating: " + GetGameRating());
	Line();
	if (app->IsUserLoggedIn()) {
		if (alreadyOwn())
		{
			Line("You Own This Game");
			Option('U', "Rate game: Thumbs Up");
			Option('D', "Rate game: Thumbs Down");
		}
		else
		{
			Option('P', "Purchase Game");
		}
	}
}
bool GameMenu::HandleChoice(char choice)
{

	switch (choice)
	{
	case 'P':
	{
		buyGame();
	}
	break;
	case 'U':
	{
		//we havew the game
		//che




		app->GetCurrentUser()->getLibraryItems()[GetPosOfLibraryItem()]->setRating(true);

	}
	break;
	case 'D':
	{
		app->GetCurrentUser()->getLibraryItems()[GetPosOfLibraryItem()]->setRating(false);


	}
	break;

	return true;
	}
}



void GameMenu::buyGame()
{
	
	if ((game->GetCost()/100 <= app->GetCurrentUser()->getCredits()))
	{
		app->GetCurrentUser()->getLibraryItems().push_back(new LibraryItem(Date(), game, 0, 0));
		app->GetCurrentUser()->takeAwayCredits(game->GetCost()/100);
	}
	else
	{
		Line("Not Enough Credits");
	}
}

bool GameMenu::alreadyOwn()
{
	bool own = false;
	if (app->IsUserLoggedIn()) {

		for (int i = 0; i < app->GetCurrentUser()->getLibraryItems().size(); i++)
		{
			if (game->GetName() == app->GetCurrentUser()->getLibraryItems()[i]->GetGame().GetName())
			{
				own = true;
			}
		}
	}
	return own;
}

int GameMenu::GetPosOfLibraryItem()
{
	for (int i = 0; i < app->GetCurrentUser()->getLibraryItems().size(); i++)
	{
		if (game->GetName() == app->GetCurrentUser()->getLibraryItems()[i]->GetGame().GetName())
		{
			return i;
		}
	}

	//should not hit here
	return 9999999;
}

std::string GameMenu::GetGameRating()
{
	double up = 0;
	double down = 0;
	for (int i = 0; i < app->GetCurrentAccount()->listOfUsers.length(); i++)
	{
		for (int j = 0; j < app->GetCurrentAccount()->listOfUsers[i]->getLibraryItems().size(); j++)
		{
			if (app->GetCurrentAccount()->listOfUsers[i]->getLibraryItems()[j]->GetGame().GetName() == game->GetName())
			{
				if (app->GetCurrentAccount()->listOfUsers[i]->getLibraryItems()[j]->getRating() == true)
				{
					up++;
				}
				else
				{
					down++;
				}
			}
		}
	}
	double percent =  up / (up + down) * 100;
	return to_string((int)percent) + "%";
}