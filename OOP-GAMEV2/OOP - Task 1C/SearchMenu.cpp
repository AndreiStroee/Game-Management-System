#include "SearchMenu.h"
#include "SearchResults.h"


SearchMenu::SearchMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void SearchMenu::OutputOptions() 
{
	Line("N) Search by name.");
	Line("P) Search by Price.");
}

bool SearchMenu::HandleChoice(char choice)
{
	if (choice == 'N' || choice == 'n')
	{
		std::string searchText = Question("Enter name");
		SearchResults sr("Search Results", app, app->GetStore().searchByName(searchText));

	}
	else if (choice == 'P' || choice == 'p')
	{
		std::string searchText = Question("Enter a price range (e.g. 5-10)");
		SearchResults sr("Search Reults", app, app->GetStore().searchByPrice(searchText));

	}
	
	return false;
}