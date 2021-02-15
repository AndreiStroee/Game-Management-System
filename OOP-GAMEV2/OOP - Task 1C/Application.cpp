#include "Application.h"
#include "Utils.h"
#include "Admin.h"
#include <fstream>

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete listOfAccounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Store& Application::GetStore()
{
	return store;
}


bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	//currentAccount = listOfAccounts[0];
	for (int i = 0; i < listOfAccounts.length(); i++)
	{
		if (listOfAccounts[i]->getEmail() == email)
		{
			if (listOfAccounts[i]->getPassword() == password)
			{
				currentAccount = listOfAccounts[i];
				
				return true;
			}
		}
	}

}


bool Application::LoginUser(const std::string& username, const std::string& password)
{

	//currentUser = currentAccount->listOfUsers[0];
	for (int i = 0; i < currentAccount->listOfUsers.length(); i++)
	{
		if (currentAccount->listOfUsers[i]->GetUsername() == username)
		{
			if (currentAccount->listOfUsers[i]->GetPassword() == password)
			{
				currentUser = currentAccount->listOfUsers[i];
				return true;
			}
		}
	}

	//return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::LogoutAccount()
{
	currentAccount = nullptr;
}

void Application::Load()
{
	int no_of_lines = 0;
	std::string line;
	ifstream myfile("data.txt");

	//GetStore().getListOfGames().addAtEnd(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	int accountCounter = 0;
	int userCounter = 0;
	while (std::getline(myfile, line))
	{

		if (line == "GAME")
		{
			std::string gameNumber;
			std::string gameName;
			std::string gameDescription;
			std::string gameCost;
			std::string gameAgeRating;

			getline(myfile, gameNumber);
			getline(myfile, gameName);
			getline(myfile, gameDescription);
			getline(myfile, gameCost);
			getline(myfile, gameAgeRating);
			int gCost = stoi(gameCost);
			int gAge = stoi(gameAgeRating);
			GetStore().getListOfGames().addAtEnd(new Game(gameName, gameDescription, gCost, gAge));
		}

		if (line == "ACCOUNT")
		{
			std::string accountDate;
			std::string accountEmail;
			std::string accountPassword;
			getline(myfile, accountDate);
			getline(myfile, accountEmail);
			getline(myfile, accountPassword);

			listOfAccounts.addInFront(new Account(accountEmail, accountPassword, Utils::convertStrToArrDate(accountDate)));

			//accountCounter++;
		}

		if (line == "ADMIN")
		{
			std::string adminName;
			std::string adminPassword;
			std::string adminDate;
			std::string adminCredits;

			getline(myfile, adminName);
			getline(myfile, adminPassword);
			getline(myfile, adminDate);
			getline(myfile, adminCredits);

			double cred = stod(adminCredits);
			listOfAccounts[accountCounter]->listOfUsers.addAtEnd(new Admin(adminName, adminPassword, Utils::convertStrToArrDate(adminDate), cred));

		}

		if (line == "PLAYER")
		{
			std::string adminName;
			std::string adminPassword;
			std::string adminDate;
			std::string adminCredits;

			getline(myfile, adminName);
			getline(myfile, adminPassword);
			getline(myfile, adminDate);
			getline(myfile, adminCredits);

			double cred = stod(adminCredits);
			listOfAccounts[accountCounter]->listOfUsers.addAtEnd(new Player(adminName, adminPassword, Utils::convertStrToArrDate(adminDate), cred));

		}

		if (line == "LIBRARYITME")
		{
			std::string gameNumber;
			std::string dateBought;
			std::string userPos;
			std::string time;
			std::string rating;

			getline(myfile, gameNumber);
			getline(myfile, dateBought);
			getline(myfile, userPos);
			getline(myfile, time);
			getline(myfile, rating);

			int gN = stoi(gameNumber);
			int uN = stoi(userPos);
			double timePlayed = stod(time);
			int rat = stoi(rating);

			listOfAccounts[accountCounter]->listOfUsers[uN]->getLibraryItems().push_back(new LibraryItem(Utils::convertStrToArrDate(dateBought), GetStore().getListOfGames()[gN], 0, 0));
			listOfAccounts[accountCounter]->listOfUsers[uN]->getLibraryItems().back()->setTimePlayed(timePlayed);
			listOfAccounts[accountCounter]->listOfUsers[uN]->getLibraryItems().back()->setRating(rat);
		}
		userCounter++;

	}
}

void Application::Save()
{
	ofstream savefile;
	savefile.open("data.txt", std::fstream::out | std::fstream::trunc);

	//games
	for (int i = 0; i < GetStore().getListOfGames().length(); i++)
	{
		savefile << "GAME" << "\n";
		savefile << i << "\n";
		savefile << GetStore().getListOfGames()[i]->GetName() << "\n";
		savefile << GetStore().getListOfGames()[i]->GetDescription() << "\n";
		savefile << GetStore().getListOfGames()[i]->GetCost() << "\n";
		savefile << GetStore().getListOfGames()[i]->GetAgeRating() << "\n";
	}

	//acounts
	for (int i = 0; i < listOfAccounts.length(); i++)
	{
		savefile << "ACCOUNT" << "\n";
		savefile << listOfAccounts[i]->getDate() << "\n";
		savefile << listOfAccounts[i]->getEmail() << "\n";
		savefile << listOfAccounts[i]->getPassword() << "\n";
		//loop through users if user admin print admin title

		for (int j = 0; j < listOfAccounts[i]->listOfUsers.length(); j++)
		{
			if (listOfAccounts[i]->listOfUsers[j]->isAdmin())
			{
				savefile << "ADMIN" << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->GetUsername() << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->GetPassword() << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->getDate() << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->getCredits() << "\n";

			}
			else
			{
				savefile << "PLAYER" << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->GetUsername() << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->GetPassword() << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->getDate() << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->getCredits() << "\n";
			}

			for (int k = 0; k < listOfAccounts[i]->listOfUsers[j]->getLibraryItems().size(); k++)
			{
				savefile << "LIBRARYITME" << "\n";
				savefile << GetGameNumber(&listOfAccounts[i]->listOfUsers[j]->getLibraryItems()[k]->GetGame(), listOfAccounts[i]->listOfUsers[j]) << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->getLibraryItems()[k]->getDatePurchased().DateToString() << "\n";
				savefile << j << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->getLibraryItems()[k]->getTimePlayed() << "\n";
				savefile << listOfAccounts[i]->listOfUsers[j]->getLibraryItems()[k]->getRating() << "\n";
			}
		}

		savefile.close();
	}
}

int Application::GetGameNumber(Game* Librarygame, User* user)
{
	//for every game
	for (int i = 0; i < GetStore().getListOfGames().length(); i++)
	{
		//if our library itme name == game name
		if (Librarygame->GetName() == GetStore().getListOfGames()[i]->GetName())
		{
			return i;
		}
	}
}

