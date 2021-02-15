#include "Account.h"
#include "Date.h"
#include "List.h"
#include "Guest.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < listOfUsers.length(); ++i)
	{
		delete listOfUsers[i];
	}
}


std::string Account::getEmail()
{
	return email;
}

std::string Account::getPassword()
{
	return password;
}

std::string Account::getDate()
{
	return created.DateToString();
}

