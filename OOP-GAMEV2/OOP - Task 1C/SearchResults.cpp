#include "SearchResults.h"
#include "GameMenu.h"

SearchResults::SearchResults(const std::string& title, Application* app, List<Game*>& listOfGames) : Menu(title, app), listOfGames(listOfGames)
{
	Paint();
}
void SearchResults::OutputOptions()
{
	for (int i = 0; i < listOfGames.length(); i++) 
	{
		Option(i+1, listOfGames[i]->GetName());
	}
	
}

bool SearchResults::HandleChoice(char choice)
{
	int index = choice - '1';
	if (index >= 0 && index < listOfGames.length())
	{
		GameMenu gm(listOfGames[index]->GetName(), app, listOfGames[index]);

	}
	return false;
}