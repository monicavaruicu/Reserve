#include <fstream>
#include <string>
#include <sstream>
#include "Reserve.h"
#include "Bear.h"
#include "Deer.h"
#include "Fox.h"
#include "Lion.h"
#include "Rabbit.h"

Reserve::Reserve()
{
	numberOfAnimals = 0;
	animals = new Animal*;
}

Reserve::~Reserve()
{
	delete[] animals;
}

void Reserve::addAnimals(std::ifstream& fin)
{
	int noOfAnimals = -1;
	fin >> noOfAnimals;

	if (noOfAnimals == -1)
	{
		std::cout << "You cannot add animals anymore! End of the file!\n";
		return;
	}

	animals = new Animal* [noOfAnimals];

	fin.ignore();
	fin.get();

	std::string opt;

	while (noOfAnimals)
	{
		std::getline(fin, opt);
		
		if (opt == "bear")
		{
			animals[numberOfAnimals] = new Bear();
			animals[numberOfAnimals]->addAnimal(fin);
			numberOfAnimals++;
		}

		if (opt == "deer")
		{
			animals[numberOfAnimals] = new Deer();
			animals[numberOfAnimals]->addAnimal(fin);
			numberOfAnimals++;
		}

		if (opt == "fox")
		{
			animals[numberOfAnimals] = new Fox();
			animals[numberOfAnimals]->addAnimal(fin);
			numberOfAnimals++;
		}

		if (opt == "lion")
		{
			animals[numberOfAnimals] = new Lion();
			animals[numberOfAnimals]->addAnimal(fin);
			numberOfAnimals++;
		}
		
		if (opt == "rabbit")
		{
			animals[numberOfAnimals] = new Rabbit();
			animals[numberOfAnimals]->addAnimal(fin);
			numberOfAnimals++;
		}
		
		noOfAnimals--;
	}

}

void Reserve::printAllAnimalsDetails()
{
	for (int i = 0; i < numberOfAnimals; i++)
	{
		animals[i]->printAnimalDetails();
		std::cout << "\n";
	}
}

void Reserve::printBears()
{
	for (int i = 0; i < numberOfAnimals; i++)
		if (animals[i]->getType() == "bear")
			animals[i]->printAnimalDetails();
}

void Reserve::printDeers()
{
	for (int i = 0; i < numberOfAnimals; i++)
		if (animals[i]->getType() == "deer")
			animals[i]->printAnimalDetails();
}

void Reserve::printFoxes()
{
	for (int i = 0; i < numberOfAnimals; i++)
		if (animals[i]->getType() == "fox")
			animals[i]->printAnimalDetails();
}

void Reserve::printLions()
{
	for (int i = 0; i < numberOfAnimals; i++)
		if (animals[i]->getType() == "lion")
			animals[i]->printAnimalDetails();
}

void Reserve::printRabbits()
{
	for (int i = 0; i < numberOfAnimals; i++)
		if (animals[i]->getType() == "rabbit")
			animals[i]->printAnimalDetails();
}

void Reserve::menu(std::ifstream& fin)
{
	int opt = -1;

	while (opt != 8)
	{
		options();
		std::cin >> opt;
		std::cout << "\n";

		switch (opt)
		{
		case 1:
			system("cls");
			addAnimals(fin);
			std::cout << "\n";
			break;
		case 2:
			system("cls");
			printAllAnimalsDetails();
			break;
		case 3:
			system("cls");
			printBears();
			std::cout << "\n";
			break;
		case 4:
			system("cls");
			printDeers();
			std::cout << "\n";
			break;
		case 5:
			system("cls");
			printFoxes();
			std::cout << "\n";
			break;
		case 6:
			system("cls");
			printLions();
			std::cout << "\n";
			break;
		case 7:
			system("cls");
			printRabbits();
			std::cout << "\n";
			break;
		case 8:
			break;
		default:
			system("cls");
			std::cout << "Invalid option!\n\n";
		}

	}

}

void Reserve::options()
{
	std::cout << "1. Add animals" << "\n";
	std::cout << "2. Print all animals" << "\n";
	std::cout << "3. Print all bears" << "\n";
	std::cout << "4. Print all deers" << "\n";
	std::cout << "5. Print all foxes" << "\n";
	std::cout << "6. Print all lions" << "\n";
	std::cout << "7. Print all rabbits" << "\n";
	std::cout << "8. Exit menu" << "\n";
	std::cout << "Your option: ";
}

