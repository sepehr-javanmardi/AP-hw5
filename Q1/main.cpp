#include <iostream>
#include <cmath>
#include <algorithm>
#include "map.h"


int main()
{
	int n{};
	std::cout << "enter the number of streets: " << std::endl;
	std::cin >> n;
	Map waze{n};
	waze.showMap();
	waze.findRoute1();
	waze.showRoute1();
	waze.findRoute2();
	waze.showRoute2();
	waze.findbRoute();
	waze.showbRoute();
	return 0;
}