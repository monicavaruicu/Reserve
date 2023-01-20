#pragma once
#include "HerbivoreAnimal.h"

class Rabbit : public HerbivoreAnimal
{
public:
	Rabbit();
	Rabbit(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, int myMinimumArea);
	~Rabbit();
	void addAnimal(std::ifstream& fin);
	std::string getType();
	void printAnimalDetails();

private:
	int minimumArea;
};

