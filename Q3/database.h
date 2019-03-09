#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <iostream>

class database
{
public:
	std::string date;
	int product_ID{};
	int costumer_ID{};
	database(std::string Date , int product_id ,int costumer_id);
	~database();
};

#endif