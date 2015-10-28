using namespace std;
#include<iostream>
#include "Country.h"
#include "Continent.h"
#include "Map.h"
#include "Player.h"

int main() {

	cout << "Welcome to RISK Map Demo" << endl;


	//1. Map
	Map Risk_Map = Map("Classic Risk Map", 6, 24);


	////2. Continents (6)
	//Continent Europe = Continent("Europe", 5);
	//Risk_Map.addContinentsToMap(Europe);
	//Continent Asia = Continent("Asia", 7);
	//Risk_Map.addContinentsToMap(Asia);
	//Continent North_America = Continent("North_America", 5);
	//Risk_Map.addContinentsToMap(North_America);
	//Continent South_America = Continent("South_America", 2);
	//Risk_Map.addContinentsToMap(South_America);
	//Continent Africa = Continent("Africa", 3);
	//Risk_Map.addContinentsToMap(Africa);
	//Continent Australia = Continent("Australia", 2);
	//Risk_Map.addContinentsToMap(Australia);

	////3. Countries (24)

	////North American Countries (9)
	//Country Alaska = Country("Alaska");
	//Country Alberta = Country("Alberta");

	////Europe (7)

	////Asia (12)

	////South America (4)

	////Africa (6)

	////Australia (2)






	Country x = Country("France");
	x.addAdjacentCountryString("England");
	cout << x.getName() << endl;

	Continent y = Continent("Europe", 7);
	//y.addCountriesToContinent(x);

	
	Risk_Map.addContinentsToMap(y);

	cout << Risk_Map.getMapVectorSize() << endl;

	Player one = Player();

	system("pause");

	return 0;
}