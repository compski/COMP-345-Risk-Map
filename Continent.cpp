#include "Continent.h"


Continent::Continent(string n, int o)
{
	name = n;
	complete_occupation_value = o;
}

Continent::Continent()
{
}

Continent::~Continent()
{
}

void Continent::addCountriesToContinent(Country c)
{
	Continent_Vector.push_back(c); //adds countries to the end of the vector
}
