#include "Store.h"
#include "Utils.h"
#include <sstream> 

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < 9; ++i)
	{
		delete listOfGames[i];
	}
}

List<Game*> &Store::getListOfGames()
{
	return listOfGames;
}

List<Game*> Store::searchByName(const std::string searchText)
{
	List<Game*> searchedGames;
	for (int i = 0; i < listOfGames.length(); i++)
	{
		if (Utils::StartsWith(listOfGames[i]->GetName(), searchText))
		{
			searchedGames.addAtEnd(listOfGames[i]);
		}
	}
	return searchedGames;
}

List<Game*> Store::searchByPrice(std::string priceRange)
{	
	std::string lhs;
	std::string rhs;

	std::string::size_type pos = priceRange.find('-');
	if (pos != std::string::npos)
	{
		lhs = priceRange.substr(0, pos);
		rhs = priceRange.substr(pos+1, priceRange.length());
	}
	
	double lhsPrice = std::stod(lhs);
	double rhsPrice = std::stod(rhs);

	List<Game*> searchedGames;
	for (int i = 0; i < listOfGames.length(); i++)
	{
		if (listOfGames[i]->GetCost()/100 >= lhsPrice && listOfGames[i]->GetCost()/100 <= rhsPrice)
		{
			searchedGames.addAtEnd(listOfGames[i]);
		}
	}
	return searchedGames;
}