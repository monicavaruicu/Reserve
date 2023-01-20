#pragma once
#include "CarnivoreAnimal.h"
#include "HerbivoreAnimal.h"

class Bear : virtual public HerbivoreAnimal, virtual public CarnivoreAnimal
{
public:
	Bear();
	Bear(std::string myName, Date* myDeliveryDate, double myWeight, std::string myFavoutiteFood, double myDailyQuantity, std::string myHibernationPeriod);
	~Bear();
	void addAnimal(std::ifstream& fin);
	std::string getType();
	void printAnimalDetails();

private:
	std::string hibernationPeriod;
};

