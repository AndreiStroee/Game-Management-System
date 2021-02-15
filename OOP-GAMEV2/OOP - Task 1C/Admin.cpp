#include "Admin.h"
#include "Date.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created, const double credits)
	: Player(username, password, created, credits)
{
}

Admin::~Admin()
{
}
 
bool Admin::isAdmin() 
{
	return true;
}