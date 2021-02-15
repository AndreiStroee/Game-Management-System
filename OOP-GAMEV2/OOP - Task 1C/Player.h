#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"
#include "Date.h"
#include "vector"

class Player : public User
{
	public:
		Player();
		Player(const std::string&, const std::string&, const Date&, const double credits);
		~Player();
		std::vector<LibraryItem*> &getLibraryItems() override;
		void deleteUser();
		double& getCredits() override;
		void addCredits(double value) override;
		void takeAwayCredits(double value) override;
		//bool isPlayer() override;
		bool isAdmin() override;
		bool isGuest() override;
	private:
		//List<LibraryItem*> listOfLibraryItems;
		std::vector<LibraryItem*> listOfLibraryItems;
		double credits;
};