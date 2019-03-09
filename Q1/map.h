#ifndef MAP_H
#define MAP_H

class Map{
public:
	Map(int n);
	~Map();
	void showMap();
	void findRoute1();
	void showRoute1();
	void findRoute2();
	void showRoute2();
	void findbRoute();
	void showbRoute();
	int n{};
	int cost1{};
	int cost2{};
	int bcost{};
	int** map_n;
	char** map_r1;
	char** map_r2;
	char** map_br;
	char* permutation;
	char* bestway;
};

#endif