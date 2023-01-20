#pragma once
#include "HerbivoreAnimal.h"
#include "CarnivoreAnimal.h"

class Fox : virtual public HerbivoreAnimal, virtual public CarnivoreAnimal
{
public:
	Fox();
	Fox(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, std::string myType, double myMaximumTemperature);
	~Fox();
	void addAnimal(std::ifstream& fin);
	std::string getType();
	void printAnimalDetails();

private:
	std::string type;
	double maximumTemperature;
};


