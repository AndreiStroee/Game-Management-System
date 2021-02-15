#include "User.h"
//#include "Date.h"

User::User(const std::string& username, const std::string& password, const Date& created)
	: username(username), password(password), created(created)
{
}

User::~User()
{
}
User::User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const std::string& User::GetPassword() const
{
	return password;
}

std::string User::getDate()
{
	return created.DateToString();
}
