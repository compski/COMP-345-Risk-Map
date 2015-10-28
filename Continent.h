#pragma once
#include "Country.h"
#include <vector>

using namespace std;

class Country;  //forward declaration

class Continent
{
public:
	Continent(string n, int o);
	Continent();
	~Continent();
	void addCountriesToContinent(Country c);
private:
	vector<Country> Continent_Vector; //this container holds the country objects
	string name;
	int complete_occupation_value; // number of bonus armies for occupying all the countries on this continent

};

