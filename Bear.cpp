#include <iostream>
#include <fstream>
#include <string>
#include "Bear.h"

Bear::Bear()
{
	name = "bear";
	hibernationPeriod = "";

	std::cout << "A bear was added!\n";
}

Bear::~Bear()
{

}

Bear::Bear(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, std::string myHibernationPeriod) :
	Animal(myName, myDeliveryDate, myWeight, myDailyQuantity)
{
	animalType = "bear";
	favouriteFood = myFavoutiteFood;
	hibernationPeriod = myHibernationPeriod;

	std::cout << "A bear was added!\n";
}

void Bear::addAnimal(std::ifstream& fin)
{
	std::string myName;
	std::string myDate;
	std::string myDay;
	std::string myMonth;
	std::string myYear;
	double myWeight = 0.0;
	std::string myFavouriteFood;
	double myDailyQuantity = 0.0;
	std::string myHibernationPeriod;

	std::getline(fin, myName);

	std::getline(fin, myDate);
	computeDate(myDate, myDay, myMonth, myYear);

	fin >> myWeight;
	fin.ignore();

	std::getline(fin, myFavouriteFood);

	fin >> myDailyQuantity;
	fin.ignore();

	std::getline(fin, myHibernationPeriod);

	fin.get();

	animalType = "bear";
	name = myName;
	deliveryDate = new Date(myDay, myMonth, myYear);
	weight = myWeight;
	favouriteFood = myFavouriteFood;
	dailyQuantity = myDailyQuantity;
	hibernationPeriod = myHibernationPeriod;
}

std::string Bear::getType()
{
	return animalType;
}

void Bear::printAnimalDetails()
{
	std::cout << "Type: " << animalType << "\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "Delivery date: ";  deliveryDate->printDate();
	std::cout << "Weight: " << weight << "\n";
	std::cout << "Favourite food: " << favouriteFood << "\n";
	std::cout << "Daily quantity of food: " << dailyQuantity << "\n";
	std::cout << "Hibernation period: " << hibernationPeriod << "\n";
}
