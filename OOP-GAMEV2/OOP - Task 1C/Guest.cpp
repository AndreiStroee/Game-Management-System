#include "Guest.h"
#include "Date.h"
#include "User.h"
#include "vector"

Guest::Guest(const std::string& username, const std::string& password, const Date& created) : User(username, password, created)
{

}

Guest::Guest() {

}

Guest::~Guest()
{
	for (int i = 0; i < getLibraryItems().size(); ++i)
	{
		delete getLibraryItems()[i];
	}
}


//override functions
std::vector<LibraryItem*>& Guest::getLibraryItems()
{
	return listOfLibraryItems;
}
double& Guest::getCredits() { return credits; }
void Guest::addCredits(double value) {}
void Guest::takeAwayCredits(double value) {}
bool Guest::isAdmin() { return false; }
bool Guest::isGuest() { return true; }

