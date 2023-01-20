#include <iostream>
#include <fstream>
#include <string>
#include "Lion.h"

Lion::Lion()
{
	name = "lion";
	minimumTemperature = INT_MAX;

	std::cout << "A lion was added!\n";
}

Lion::Lion(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, double myMinimumTemperature, std::string myCountryOfOrigin):
	Animal(myName, myDeliveryDate, myWeight, myDailyQuantity)
{
	animalType = "lion";
	favouriteFood = myFavoutiteFood;
	minimumTemperature = myMinimumTemperature;
	countryOfOrigin = myCountryOfOrigin;

	std::cout << "A lion was added!\n";
}

Lion::~Lion()
{

}

void Lion::addAnimal(std::ifstream& fin)
{
	std::string myName;
	std::string myDate;
	std::string myDay;
	std::string myMonth;
	std::string myYear;
	double myWeight = 0.0;
	std::string myFavouriteFood;
	double myDailyQuantity = 0.0;
	double myMinimumTemperature = INT_MAX;
	std::string myCountryOfOrigin;

	std::getline(fin, myName);

	std::getline(fin, myDate);
	computeDate(myDate, myDay, myMonth, myYear);

	fin >> myWeight;
	fin.ignore();

	std::getline(fin, myFavouriteFood);

	fin >> myDailyQuantity;

	fin >> myMinimumTemperature;

	fin.ignore();

	std::getline(fin, myCountryOfOrigin);

	fin.get();

	animalType = "lion";
	name = myName;
	deliveryDate = new Date(myDay, myMonth, myYear);
	weight = myWeight;
	favouriteFood = myFavouriteFood;
	dailyQuantity = myDailyQuantity;
	minimumTemperature = myMinimumTemperature;
	countryOfOrigin = myCountryOfOrigin;
}

std::string Lion::getType()
{
	return animalType;
}

void Lion::printAnimalDetails()
{
	std::cout << "Type: " << animalType << "\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "Delivery date: ";  deliveryDate->printDate();
	std::cout << "Weight: " << weight << "\n";
	std::cout << "Favourite food: " << favouriteFood << "\n";
	std::cout << "Daily quantity of food: " << dailyQuantity << "\n";
	std::cout << "Minimum temperature supported: " << minimumTemperature << " degrees Celsius\n";
	std::cout << "Country of origin: " << countryOfOrigin << "\n";
}
