#pragma once

#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> &getListOfGames();
		List<Game*> searchByName(std::string searchText);
		List<Game*> searchByPrice(std::string priceRange);
		
		//Game* games[9] = { }; // TODO: should be a dynamic collection

	private:
		List<Game*>listOfGames;

};