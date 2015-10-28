#include <iostream>
#include "SaveLoad.h"

using namespace std;

int main() {

	cout << SaveLoad::loadMap("Map.map") << endl;

	system("pause");
	return 0;
};