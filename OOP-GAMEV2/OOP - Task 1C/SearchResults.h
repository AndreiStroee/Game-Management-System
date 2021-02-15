#pragma once
#include "Menu.h"


class SearchResults : public Menu
{
public:
	SearchResults(const std::string& title, Application *app, List<Game*>&listOfGames);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	List<Game*>& listOfGames;
};
