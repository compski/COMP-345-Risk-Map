#include "Country.h"
#include "Continent.h"

Country::Country()
{

}

Country::Country(string n)
{
	name = n;
}


Country::~Country()
{
}

void Country::addAdjacentCountryString(string c)
{
	Adjacent_Countries.push_back(c); //push.back() adds data element to the end of the array
}

void Country::setContinent(Continent c)
{
	belongs_to_this_continent = c;
}

void Country::setOwner(Player p)
{
	owner = p;
}

string Country::getName()
{
	return name;
}
