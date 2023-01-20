#pragma once
#include <iostream>
#include "Date.h"

class Animal
{
public:
	Animal();
	Animal(std::string myName, Date* myDeliveryDate, double myWeight, double myDailyQuantity);
	~Animal();
	virtual std::string getType() = 0;
	virtual void printAnimalDetails() = 0;
	virtual void addAnimal(std::ifstream& fin) = 0;
	void computeDate(std::string myDate, std::string& myDay, std::string& myMonth, std::string& myYear);

protected:
	std::string animalType;
	std::string name;
	Date* deliveryDate;
	double weight;
	std::string favouriteFood;
	double dailyQuantity;
};



