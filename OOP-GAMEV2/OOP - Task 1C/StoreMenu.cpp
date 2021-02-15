#include "StoreMenu.h"
#include "GameMenu.h"
#include "SearchMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
		Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
		for (int i = 0; i < app->GetStore().getListOfGames().length(); i++)
		{
				// adding 1 so the display is nicer for the user
				Option(i + 1, app->GetStore().getListOfGames()[i]->GetName());
			

		}
	Line();
	Line("S) Search");

}

bool StoreMenu::HandleChoice(char choice)
{
		// since we are using numbers here we shift the char down by '1'
		// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
		// this reverses the + 1 above and lets us do the range check below
	if (choice == 'S' || choice == 's')
	{
		SearchMenu sm("Search Menu", app);
	}
		int index = choice - '1';

		if (index >= 0 && index < app->GetStore().getListOfGames().length())
		{
			GameMenu gm(app->GetStore().getListOfGames()[index]->GetName(), app, app->GetStore().getListOfGames()[index]);
		
		}

		return false;
}