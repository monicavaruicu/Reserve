#include <fstream>
#include <string>
#include <sstream>
#include "Animal.h"

Animal::Animal():animalType("animal"), name("animal"), deliveryDate(new Date), weight(0.0), favouriteFood("food"), dailyQuantity(0.0)
{

}

Animal::Animal(std::string myName, Date* myDeliveryDate, double myWeight, double myDailyQuantity)
{
	animalType = "animal";
	name = myName;
	deliveryDate = myDeliveryDate;
	weight = myWeight;
	dailyQuantity = myDailyQuantity;
}

Animal::~Animal()
{

}

void Animal::computeDate(std::string myDate, std::string& myDay, std::string& myMonth, std::string& myYear)
{
	std::istringstream iss(myDate);
	std::string token;

	int opt = 1;

	while (std::getline(iss, token, '/'))
	{
		switch (opt)
		{
		case 1:
			myDay = token;
			opt++;
			break;
		case 2:
			myMonth = token;
			opt++;
			break;
		case 3:
			myYear = token;
			opt++;
			break;
		}
	}

}