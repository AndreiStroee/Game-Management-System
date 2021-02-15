#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date, Game*, double, bool);
		~LibraryItem();
		Game GetGame();
		Date getDatePurchased();
		double getTimePlayed();
		void setTimePlayed(double timePlayed);
		bool getRating();
		void setRating(bool);
	private:
		const Game* game;
		const Date purchased;  
		double timePlayed;
		bool playerRating;
};