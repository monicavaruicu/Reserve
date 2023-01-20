#include <iostream>
#include <fstream>
#include <string>
#include "Rabbit.h"

Rabbit::Rabbit()
{
	name = "rabbit";
	minimumArea = 0;

	std::cout << "A rabbit was added!\n";
}

Rabbit::Rabbit(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, int myMinimumArea):
	Animal(myName, myDeliveryDate, myWeight, myDailyQuantity)
{
	animalType = "rabbit";
	favouriteFood = myFavoutiteFood;
	minimumArea = myMinimumArea;

	std::cout << "A rabbit was added!\n";
}

Rabbit::~Rabbit()
{

}

void Rabbit::addAnimal(std::ifstream& fin)
{
	std::string myName;
	std::string myDate;
	std::string myDay;
	std::string myMonth;
	std::string myYear;
	double myWeight = 0.0;
	std::string myFavouriteFood;
	double myDailyQuantity = 0.0;
	int myMinimumArea = 0;

	std::getline(fin, myName);

	std::getline(fin, myDate);
	computeDate(myDate, myDay, myMonth, myYear);

	fin >> myWeight;
	fin.ignore();

	std::getline(fin, myFavouriteFood);

	fin >> myDailyQuantity;
	fin.ignore();

	fin >> myMinimumArea;

	fin.ignore();
	fin.get();

	animalType = "rabbit";
	name = myName;
	deliveryDate = new Date(myDay, myMonth, myYear);
	weight = myWeight;
	favouriteFood = myFavouriteFood;
	dailyQuantity = myDailyQuantity;
	minimumArea = myMinimumArea;
}

std::string Rabbit::getType()
{
	return animalType;
}

void Rabbit::printAnimalDetails()
{
	std::cout << "Type: " << animalType << "\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "Delivery date: ";  deliveryDate->printDate();
	std::cout << "Weight: " << weight << "\n";
	std::cout << "Favourite food: " << favouriteFood << "\n";
	std::cout << "Daily quantity of food: " << dailyQuantity << "\n";
	std::cout << "Minimum required area: " << minimumArea << " squared meters\n";
}
