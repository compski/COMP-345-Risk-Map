#pragma once
#include "Map.h"

//using namespace to implement the saveload as an utility and not object class.
namespace SaveLoad
{
	bool saveMap(Map &mapObject, std::string fileLocation);
	Map loadMap(std::string fileLocation);
}
