#include "Utils.h"
#include <iomanip>
#include "Date.h"
#include <iostream>
#include "LibraryItem.h"

std::string Utils::getLineFromUser()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

char Utils::getCharFromUser()
{
	return toupper(getLineFromUser()[0]);
}

bool Utils::StartsWith(std::string fullText, std::string searchText)
{
	if (fullText.find(searchText) == 0) {
		return true;
	}
	else return false;
}

Date Utils::convertStrToArrDate(string date)
{
	const int date_length = 10;
	int arr[date_length] = { 0 };

	int j = 0;
	int i;

	for (i = 0; date[i] != '\0'; i++) {

		if (date[i] == '/') {
			j++;
		}
		else {
			arr[j] = arr[j] * 10 + (date[i] - 48);
		}
	}

	return Date(arr[0], arr[1], arr[2]);
}

std::string Utils::upperCaseFor(std::string text)
{
	for (int i = 0; i < text.size(); i++)
	{
		text[i] = toupper(text[i]); //or -32 from the text[] instead of using stl toupper
	}
	return text;
}

std::string Utils::upperCaseRecursive(std::string text)
{
	if (text.length() == 0) return "";
	return (char)toupper(text[0]) + upperCaseRecursive(text.substr(1));
}

double Utils::addRandomNumber(double number)
{
	if (number <= 58)
	{
		number += rand() % 10;//random number between 1-9
	}
	else if (number >= 59 && number <= 299)
	{
		number += rand() % 41 + 10;//random number between 10-50
	}
	else if (number >= 300)
	{
		number += 60;
	}

	return number;
}

std::string Utils::formatTime(double number)
{
	if (number <= 59)
	{
		return " (" + to_string(int(number)) + (" Minute(s))");
	}
	else if (number > 59 && number <= 299)
	{
		int f = (int)number % 10;
		int nr = (int)number / 60;
		return " (" + to_string(nr) + "." + to_string(f) + " Hour(s))";
	}
	else if (number >= 300)
	{
		return " (" + to_string(int(number / 60)) + " Hours)";
	}

	return "9999999999999999";
}

static bool gameInLibraryItems(std::string name, std::vector<LibraryItem*>* list)
{

	for (int i = 0; i < list->size(); i++)
	{
		if (list->at(i)->GetGame().GetName() == name)
		{
			//would be better to give every game a unique ID
			return true;
		}
	}

	return false;

}