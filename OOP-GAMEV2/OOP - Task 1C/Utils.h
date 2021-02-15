#pragma once

#include <iostream>
#include "Date.h"
#include <vector>
#include "LibraryItem.h"

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    static bool StartsWith(std::string fullText, std::string searchText);
    static Date convertStrToArrDate(std::string date);
    static std::string upperCaseFor(std::string text);
    static std::string upperCaseRecursive(std::string text);
    static double addRandomNumber(double number);
    static std::string formatTime(double number);
    //static bool gameInLibraryItems(std::string name, std::vector<LibraryItem*>* list);
};