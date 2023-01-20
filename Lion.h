#pragma once
#include "CarnivoreAnimal.h"

class Lion : public CarnivoreAnimal
{
public:
	Lion();
	Lion(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, double myMinimumTemperature, std::string myCountryOfOrigin);
	~Lion();
	void addAnimal(std::ifstream& fin);
	std::string getType();
	void printAnimalDetails();

private:
	double minimumTemperature;
	std::string countryOfOrigin;
};

