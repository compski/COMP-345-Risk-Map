#include "SaveLoad.h"
#include "Map.h"
#include "Country.h"
#include "Continent.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace SaveLoad {

	Map loadMap(string mapLocation){
		
		Map mapObject;
		//TO BE STORED

		Map mapObject;
		string mapName = mapLocation.substr(0, mapLocation.find('.'));
		int numContinents = 0;
		int numCountries = 0;

		fstream mapFile;
		mapFile.open(mapLocation, ios::in);
		int count = 0;

		string line;
		string value;
		string name;
		string section;

		/*BEGINNING OF FILE EXTRACTION*/
		while (!mapFile.eof()){

			getline(mapFile, line, '\n');
			
			if (line.empty()) continue;

			if (line[0] == '[') {
				section = line.substr(1, line.length() - 2);
				cout << section << endl;
				continue;
			}
			
			/*MAP FILE SETTINGS EXTRACTION*/ 
			if (section.compare("Map") == 0) {				//DONE:: NOTHING TO EXTRACT
				int equalSign = line.find('=');
				name = line.substr(0, equalSign);
				value = line.substr(equalSign + 1, line.length() - 1);
				continue;
			}
			/*END OF MAP FILE SETTING*/

			/*CONTINENT SECTION EXTRACTION*/				//DONE:: ADDED CONTINENT TO MAP OBJECT
			if (section.compare("Continents") == 0) {
				int equalSign = line.find('=');
				name = line.substr(0, equalSign);
				value = line.substr(equalSign + 1, line.length() - 1);

				Continent temp(name, std::stoi(value, 0, 10));
				mapObject.addContinentsToMap(temp);
				numContinents++;
				continue;
			}
			/*END OF CONTINENT SECTION EXTRACTION*/

			/*TERRITORY SECTION EXTRACTION*/
			if (section.compare("Territories") == 0) {				//NOT DONE:: NEEDS EXTRACTION CONTINENT FROM MAP, MORE METHODS FROM MAP
				Country temp;

				/*WHILE LOOP EXTRACTS THE VALUES IN EACH COUNTRY LINE*/
				bool end = false;
				int TYPE = 0;
				while (!end) {
					/*GET VALUE OF EACH ELEMENT IN THE LINE*/
					int commas = line.find(',');
					if (commas == -1) {
						commas = line.length();
						end = true;
					}
					value = line.substr(0, commas);
					if (!end) line = line.substr(commas + 1, line.length());
					/*END OF GET VALUE*/

					/*INSERTION OF VALUES TO TEMPORARY COUNTRY DEPENDING ON POSITION OF TYPE*/
					switch (TYPE) {
						case 0:										//NOT DONE
							temp.setCountryName(value);
							break; //NAME
						case 1:										//NOT DONE 
							temp.setXCordinate(stoi(value, 0, 10));
							break; //X CORDINATE
						case 2:										//NOT DONE
							temp.setYCordinate(stoi(value, 0, 10));
							break; //Y CORDINATE
						case 3:										//NOT DONE FIND CONTINENT IN MAP OBJECT WITH THE USE OF STRING
							temp.setContinent();
							//ONCE FINDING THE CONTINUENT ADD COUNTRY TO CONTINENT;
							break; //CONTINENTS 
						default: //ADJACENT COUNTRIES				//DONE
							temp.addAdjacentCountryString(value);
					}
					/*END OF INSERTION*/

					TYPE++;
				}
				cout << endl;
				numCountries++;
				continue;
			}
			/*END OF TERRITORY SECTION EXTRACTION*/
			
		} /*END OF FILE EXTRACTION*/

		mapObject.setNumCountries(numCountries);
		mapObject.setNumContinents(numContinents);
		return mapObject;
	}

	bool saveMap(Map &mapObject, string fileLocation) { 
		fstream mapFile;
		mapFile.open(fileLocation, ios::out);
		
		//map settings, write properties.
		mapFile << "[Map]" << endl;
		string settings[5] = {"author=","image=","wrap=","scroll=","warn="};
		for (int i = 0; i < 5; i++)	{
			mapFile << settings[i] << "" << endl;
		}
		//for each continent write the bonus;				//GET NUM CONTINENT, WRONG NAME***
		mapFile << "[Continents]" << endl;
		for (int i = 0; i < mapObject.getMapVectorSize(); i++){

		}

		mapFile << "[Territories]" << endl;					//GET NUM CONTUNRY***, WHERE IS
		for (int i = 0; i < mapObject.getNumCountry(); i++){
			
		}

		mapFile.close();
		return true;
	}

}