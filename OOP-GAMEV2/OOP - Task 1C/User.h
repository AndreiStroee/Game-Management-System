#pragma once

#include <string>
#include "Date.h"
#include "LibraryItem.h"
#include "List.h"
#include "vector"

class User
{
	public:
		User(const std::string& username, const std::string& password, const Date& created);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		virtual std::vector<LibraryItem*> &getLibraryItems() = 0;
		virtual double& getCredits() = 0;
		virtual void addCredits(double value) = 0;
		virtual void takeAwayCredits(double value) = 0;
		virtual bool isAdmin() = 0;
		virtual bool isGuest() = 0;
		std::string getDate();
		User();
	private:
		std::string username;
		std::string password;
		Date created;  
};

//User could have a function which gives access
//to that user's collection of games, and Player could override that.