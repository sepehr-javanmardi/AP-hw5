#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include"database.h"


int main(){

	std::string date{};                   // for date in db.txt
	int product_ID{};	                  // for product number in db.txt
	int costumer_ID{};	                  // for costumer number in db.txt
	int c{};                              // argoman of dates
	bool repeat{false};                   // for fin repeats
	std::string temp{};                   // for temporary values in db.txt
	std::vector<database> Data{};         // for storing data in objects of class
	std::vector<std::string> dates{};     // for saving diffrent dates
	std::vector<int> costumers{};         // for saving diffrent costumer numbers
	std::vector<int> products;            // for saving diffrent product numbers

	std::ifstream input{"db.txt"};	      //reading db.txt
		while (!input.eof())
		{
        	std::getline(input, temp, '[');
       		std::getline(input, date, ' ');
        	std::getline(input, temp, ' ');
			input >> product_ID;
        	input >> costumer_ID;
        	database a(date, product_ID, costumer_ID);
        	Data.push_back(a);
		}
    input.close();
    	
    dates.push_back(Data[0].date);        //creatind list
    costumers.push_back(Data[0].costumer_ID);
    products.push_back(Data[0].product_ID);

    std::ofstream output{};               //creating output file
	output.open("dbnew.txt", std::ofstream::app);


    for(size_t i{1}; i < size(Data); i++) //algorithem for shortening the data
    { 
    	if (dates[c] != Data[i].date)
    	{
    		output << dates[c] << " ";
    		output << size(products) << " " << size(costumers) << std::endl;

    		dates.clear();
    		costumers.clear();
    		products.clear();

			dates.push_back(Data[i].date);
			costumers.push_back(Data[i].costumer_ID);
			products.push_back(Data[i].product_ID);
		}
		else
		{
			for(size_t j{0}; j < size(costumers) ; j++)
			{
				if(costumers[j] == Data[i].costumer_ID)
				{
					repeat = true;
				}
			}

			if(!repeat)
			{
				costumers.push_back(Data[i].costumer_ID);
				repeat = false;
			}

			repeat = false;
			
			for(size_t j{0}; j < size(products) ; j++)
			{
				if(products[j] == Data[i].product_ID)
				{
					repeat = true;
				}
			}
			
			if(!repeat)
			{
				products.push_back(Data[i].product_ID);	
				repeat = false;
			}	
		}
    }

    output << dates[c] << " ";
    output << products.size() << " ";
    output << costumers.size() << std::endl;
    output.close();

return 0;
}
