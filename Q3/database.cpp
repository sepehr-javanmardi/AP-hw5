#include<string>
#include<vector>
#include"database.h"

database::database(std::string Date , int product_id ,int costumer_id)
{
	date = Date;
	product_ID = product_id;
	costumer_ID = costumer_id;
}

database::~database(){
	
}