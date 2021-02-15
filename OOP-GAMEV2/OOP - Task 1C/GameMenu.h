#pragma once
#include "GameMenu.h"
#include "Menu.h"

/*
1.name of the game
2. descriptionm
3. age rating
2.price
*/

class GameMenu :public Menu 
{
public:
	GameMenu(const std::string& title, Application* app, Game* game);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	void buyGame();
	bool alreadyOwn();
	int GetPosOfLibraryItem();
	std::string GetGameRating();

private:
	Game* game;
	//double gameRating;
};