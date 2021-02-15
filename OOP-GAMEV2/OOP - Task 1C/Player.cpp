#include "Player.h"
#include "Date.h"
#include "User.h"
#include "vector"

Player::Player(const std::string& username, const std::string& password, const Date& created, const double credits) : User(username, password, created), credits(credits)
{

}

Player::Player() {

}

Player::~Player()
{
	for (int i = 0; i < getLibraryItems().size(); ++i)
	{
		delete getLibraryItems()[i];
	}
}

std::vector<LibraryItem*>& Player::getLibraryItems()
{
	return listOfLibraryItems;
}


void Player::deleteUser()
{
	for (int i = 0; i < getLibraryItems().size(); i++)
	{
		delete listOfLibraryItems[i];
	}

}

double& Player::getCredits()
{
	return credits;
}

void Player::addCredits(double value)
{
	credits += value;
}

void Player::takeAwayCredits(double value)
{
	credits -= value;
}


bool Player::isAdmin()
{
	return false;
}

bool Player::isGuest()
{
	return false;
}