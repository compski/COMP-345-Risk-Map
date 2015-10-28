#pragma once
using namespace std;
#include<string>
#include "Player.h"
#include<vector>
#include "Continent.h"

class Continent; //forward declaration

class Country
{
public:
	Country();
	Country(string n);
	~Country();
	void addAdjacentCountryString(string c);
	void setContinent(Continent c);
	void setOwner(Player p);
	string getName();

private:
	string name;
	Player owner;
	int num_armies;
	Continent belongs_to_this_continent;
	vector<string> Adjacent_Countries;

};

