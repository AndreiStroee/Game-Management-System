#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "Date.h"
#include "ListT.h"
#include "Menu.h"
#include "MainMenu.h"
#include "List.h"
#include "Guest.h"

void main()
{	
	Application application;

	application.Load();

	MainMenu main("Main Menu", &application);

	application.Save();
}
