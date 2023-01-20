#pragma once
#include "Animal.h"

class Reserve
{
public:
	Reserve();
	~Reserve();
	void addAnimals(std::ifstream&);
	void printAllAnimalsDetails();
	void printBears();
	void printDeers();
	void printFoxes();
	void printLions();
	void printRabbits();
	void menu(std::ifstream&);
	void options();

private:
	Animal** animals;
	int numberOfAnimals;
};

