#include <fstream>
#include "Reserve.h"
#include "HerbivoreAnimal.h"

std::ifstream fin("Animals.in");

int main()
{
	Reserve reserve;

	reserve.menu(fin);

	fin.close();

	return 0;
}