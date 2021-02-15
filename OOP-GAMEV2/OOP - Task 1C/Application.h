#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"

class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;
		int GetGameNumber(Game* game, User* user);


		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		void LogoutAccount();
		void Load();
		void Save();
		
		List<Account*> listOfAccounts;
		//Account* accounts[1] = { }; 
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;

};