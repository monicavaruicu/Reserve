#pragma once
#include "HerbivoreAnimal.h"

class Deer : public HerbivoreAnimal
{
public:
	Deer();
	Deer(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, int noFawns);
	~Deer();
	void addAnimal(std::ifstream& fin);
	std::string getType();
	void printAnimalDetails();

private:
	int numberOfFawns;
};

