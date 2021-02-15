#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"
#include "Date.h"
#include "vector"

class Guest : public User
{
public:
	Guest();
	Guest(const std::string&, const std::string&, const Date&);
	~Guest();

	std::vector<LibraryItem*>& getLibraryItems() override;
	double& getCredits() override;
	void addCredits(double value) override;
	void takeAwayCredits(double value) override;
	bool isAdmin() override;
	bool isGuest() override;
private:
	std::vector<LibraryItem*> listOfLibraryItems;
	double credits = 0;
};