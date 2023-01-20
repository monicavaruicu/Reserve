#include <iostream>
#include <fstream>
#include <string>
#include "Deer.h"

Deer::Deer()
{
	name = "deer";
	numberOfFawns = -1;

	std::cout << "A deer was added!\n";
}

Deer::Deer(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, int noFawns):
	Animal(myName, myDeliveryDate, myWeight, myDailyQuantity)
{
	animalType = "deer";
	favouriteFood = myFavoutiteFood;
	numberOfFawns = noFawns;

	std::cout << "A deer was added!\n";
}

Deer::~Deer()
{

}

void Deer::addAnimal(std::ifstream& fin)
{
	std::string myName;
	std::string myDate;
	std::string myDay;
	std::string myMonth;
	std::string myYear;
	double myWeight = 0.0;
	std::string myFavouriteFood;
	double myDailyQuantity = 0.0;
	int myNumberOfFawns = -1;

	std::getline(fin, myName);

	std::getline(fin, myDate);
	computeDate(myDate, myDay, myMonth, myYear);

	fin >> myWeight;
	fin.ignore();

	std::getline(fin, myFavouriteFood);

	fin >> myDailyQuantity;

	fin >> myNumberOfFawns;

	fin.ignore();
	fin.get();

	animalType = "deer";
	name = myName;
	deliveryDate = new Date(myDay, myMonth, myYear);
	weight = myWeight;
	favouriteFood = myFavouriteFood;
	dailyQuantity = myDailyQuantity;
	numberOfFawns = myNumberOfFawns;
}

std::string Deer::getType()
{
	return animalType;
}

void Deer::printAnimalDetails()
{
	std::cout << "Type: " << animalType << "\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "Delivery date: ";  deliveryDate->printDate();
	std::cout << "Weight: " << weight << "\n";
	std::cout << "Favourite food: " << favouriteFood << "\n";
	std::cout << "Daily quantity of food: " << dailyQuantity << "\n";
	std::cout << "Number of faws: " << numberOfFawns << "\n";
}
