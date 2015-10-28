#pragma once
#include "Continent.h"
#include "Country.h"
#include <vector>
using namespace std;

class Map
{
public:
	Map();
	Map(string name,int continents,int countries);
	~Map();
	void addContinentsToMap(Continent c);
	int getMapVectorSize();	//returns the number of continents

private:
	vector<Continent> Map_Vector; //This resizable container holds all the continent objects
	string name;
	int num_continents;
	int num_countries;
	string author; //Map Creator's name
	
};

