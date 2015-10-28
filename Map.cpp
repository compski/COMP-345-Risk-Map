#include "Map.h"

Map::Map()
{
}


Map::Map(string n, int continents, int countries)
{
	name = n;
	num_continents = continents;
	num_countries = countries;
}


Map::~Map()
{
}

void Map::addContinentsToMap(Continent c)
{
	Map_Vector.push_back(c); //adds continents to Map vector
}

int Map::getMapVectorSize()
{
	return Map_Vector.size(); 
}
