#include "LibraryItem.h"
#include "Date.h"

LibraryItem::LibraryItem(const Date date, Game* game, double timePlayed, bool playerRating)
	: purchased(date), game(game), timePlayed(timePlayed), playerRating(playerRating)
{
}

Game LibraryItem::GetGame()
{
	return *game;
}

Date LibraryItem::getDatePurchased()
{
	return purchased;
}

double LibraryItem::getTimePlayed()
{
	return timePlayed;
}


void LibraryItem::setTimePlayed(double timePlayed) 
{
	this->timePlayed = timePlayed;
}

bool LibraryItem::getRating()
{
	return playerRating;
}
void LibraryItem::setRating(bool playerRating)
{
	this->playerRating = playerRating;
}

LibraryItem::~LibraryItem()
{
}