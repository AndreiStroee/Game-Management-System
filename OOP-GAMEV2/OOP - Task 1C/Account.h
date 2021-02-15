#pragma once

#include <string>
#include "Player.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		List<User*> listOfUsers;
		std::string getEmail();
		std::string getPassword();
		std::string getDate();
		//User* users[3] = { };
	private:
		std::string email;
		std::string password;
		Date created;
};