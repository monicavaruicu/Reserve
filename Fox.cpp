#include <iostream>
#include <fstream>
#include <string>
#include "Fox.h"

Fox::Fox()
{
	name = "fox";
	type = "";
	maximumTemperature = INT_MIN;

	std::cout << "A fox was added!\n";
}

Fox::Fox(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, std::string myType, double myMaximumTemperature):
	Animal(myName, myDeliveryDate, myWeight, myDailyQuantity)
{
	animalType = "fox";
	favouriteFood = myFavoutiteFood;
	type = myType;
	maximumTemperature = myMaximumTemperature;

	std::cout << "A fox was added!\n";
}

Fox::~Fox()
{

}

void Fox::addAnimal(std::ifstream& fin)
{
	std::string myName;
	std::string myDate;
	std::string myDay;
	std::string myMonth;
	std::string myYear;
	double myWeight = 0.0;
	std::string myFavouriteFood;
	double myDailyQuantity = 0.0;
	std::string myType;
	double myMaximumTemperature = INT_MIN;

	std::getline(fin, myName);

	std::getline(fin, myDate);
	computeDate(myDate, myDay, myMonth, myYear);

	fin >> myWeight;
	fin.ignore();

	std::getline(fin, myFavouriteFood);

	fin >> myDailyQuantity;
	fin.ignore();

	std::getline(fin, myType);

	fin >> myMaximumTemperature;

	fin.ignore();
	fin.get();

	animalType = "fox";
	name = myName;
	deliveryDate = new Date(myDay, myMonth, myYear);
	weight = myWeight;
	favouriteFood = myFavouriteFood;
	dailyQuantity = myDailyQuantity;
	type = myType;
	maximumTemperature = myMaximumTemperature;
}

std::string Fox::getType()
{
	return animalType;
}

void Fox::printAnimalDetails()
{
	std::cout << "Type: " << animalType << "\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "Delivery date: ";  deliveryDate->printDate();
	std::cout << "Weight: " << weight << "\n";
	std::cout << "Favourite food: " << favouriteFood << "\n";
	std::cout << "Daily quantity of food: " << dailyQuantity << "\n";
	std::cout << "Type: " << type << "\n";
	std::cout << "Maximum temperature supported: " << maximumTemperature << " degrees Celsius\n";
}



