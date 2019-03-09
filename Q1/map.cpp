#include <iostream>
#include "map.h"
#include <algorithm>

Map::Map(int n)
{
	this->n = n;
	srand(time(0)); 
	map_n = new int*[n]; //creating n*n arry for map hights
	for (int i{}; i < n; i++)
	{
		map_n[i] = new int [n];
	}

	for(int i{}; i < n; i++) //filling the array with random numbers
	{
		for(int j{}; j < n; j++)
		{
			int r = (rand() % 100);
			map_n[i][j] = r;
		}
	}

	map_r1 = new char*[n]; //creating n*n arry for map routs
	for (int i{}; i < n; i++)
	{
		map_r1[i] = new char [n];
	}

	for(int i{}; i < n; i++) //filling the array with 'o'
	{
		for(int j{}; j < n; j++)
		{
			map_r1[i][j] = 'o';
		}
	}
	map_r1[0][0] = '#';

	map_r2 = new char*[n]; //creating n*n arry for map routs
	for (int i{}; i < n; i++)
	{
		map_r2[i] = new char [n];
	}

	for(int i{}; i < n; i++) //filling the array with 'o'
	{
		for(int j{}; j < n; j++)
		{
			map_r2[i][j] = 'o';
		}
	}
	map_r2[0][0] = '#';

	map_br = new char*[n]; //creating n*n arry for map routs
	for (int i{}; i < n; i++)
	{
		map_br[i] = new char [n];
	}

	for(int i{}; i < n; i++) //filling the array with 'o'
	{
		for(int j{}; j < n; j++)
		{
			map_br[i][j] = 'o';
		}
	}
	map_br[0][0] = '#';

	permutation = new char [2*(n-1)]; //array for permutation of waze
	for (int i{}; i < 2*(n-1); i++)
	{
		if(i < n-1)
		{
			permutation[i] = 'r';
		}
		else
		{
			permutation[i] = 'd';
		}
	}

	bestway = new char [2*(n-1)];  //array for best waze
	for (int i{}; i < 2*(n-1); i++)
	{
		if(i < n-1)
		{
			bestway[i] = 'r';
		}
		else
		{
			bestway[i] = 'd';
		}
	}
}

void Map::showMap()
{
	for(int i{}; i < n; i++)
	{
		for(int j{}; j < n; j++)
		{
			std::cout << map_n[i][j] << " " ;
		}
		std::cout << std::endl;
	}
}

void Map::findRoute1()
{
	int i{};
	int j{};

	while((i < n) && (j < n) )
	{

		if(i == n-1)
		{
			for (int p{}; j < n-1; p++)
			{
				cost1 += abs(map_n[i][j+1] - map_n[i][j]);
				map_r1[i][j+1] = '#';
				j++;
			}
			i++;
		}

		else if(j == n-1)
		{
			for (int p{}; i< n-1; p++)
			{
				cost1 += abs(map_n[i+1][j] - map_n[i][j]);
				map_r1[i+1][j] = '#';
				i++;
			}
			j++;
		}

		else if (abs( map_n[i+1][j] - map_n[i][j]) <= abs( map_n[i][j+1] - map_n[i][j]))
		{
			cost1 += abs( map_n[i+1][j] - map_n[i][j]);
			map_r1[i+1][j] = '#';
			i++;
		}
		else
		{
			cost1 += abs( map_n[i][j] - map_n[i][j+1]);
			map_r1[i][j+1] = '#';
			j++;
		}
	}

	std::cout << "cost1: " << cost1 << std::endl;

}

void Map::showRoute1()
{
	for(int i{}; i < n; i++)
	{
		for(int j{}; j < n; j++)
		{
			std::cout << map_r1[i][j] << " " ;
		}
		std::cout << std::endl;
	}
}

void Map::findRoute2()
{
	int i{};
	int j{};

	while((i < n) && (j < n) )
	{

		if(i == n-1)
		{
			for (int p{}; j < n-1; p++)
			{
				cost2 += abs(map_n[i][j+1] - map_n[i][j]);
				map_r2[i][j+1] = '#';
				j++;
			}
			i++;
		}

		else if(j == n-1)
		{
			for (int p{}; i< n-1; p++)
			{
				cost2 += abs(map_n[i+1][j] -map_n[i][j]);
				map_r2[i+1][j] = '#';
				i++;
			}
			j++;
		}

		else if (abs( map_n[i+1][j] - map_n[i][j]) <= abs( map_n[i][j+1] - map_n[i][j]))
		{
			if(abs( map_n[i+1][j] - map_n[i][j]) <= abs( map_n[i+1][j+1] - map_n[i][j]))
			{	
				cost2 += abs( map_n[i+1][j] - map_n[i][j]);
				map_r2[i+1][j] = '#';
				i++;
			}
			else
			{
				cost2 += abs( map_n[i+1][j+1] - map_n[i][j]);
				map_r2[i+1][j+1] = '#';
				i++;
				j++;
			}
		}
		else
		{

			if(abs( map_n[i][j+1] - map_n[i][j]) <= abs( map_n[i+1][j+1] - map_n[i][j]))
			{	
				cost2 += abs( map_n[i][j+1] - map_n[i][j]);
				map_r2[i][j+1] = '#';
				j++;
			}
			else
			{
				cost2 += abs( map_n[i+1][j+1] - map_n[i][j]);
				map_r2[i+1][j+1] = '#';
				i++;
				j++;
			}
		}
	}

	std::cout << "cost2: " << cost2 << std::endl;
}

void Map::showRoute2()
{
	for(int i{}; i < n; i++)
	{
		for(int j{}; j < n; j++)
		{
			std::cout << map_r2[i][j] << " " ;
		}
		std::cout << std::endl;
	}
}

void Map::findbRoute()
{
  	std::sort (permutation, permutation + (2*(n-1)));
  	
  	int bcost{200*n};
  	int temp{};

  	do
  	{
  		int i = 0;
  		int j = 0;
  		int p = 0;
  		int q = 0;
    	for(int k{}; k < 2*(n-1); k++)
    	{
    		if(permutation[p] == 'r')
    		{
    			temp += abs(map_n[i][j+1] - map_n[i][j]);
    			j++;
    		}
    		else
    		{
    			temp += abs(map_n[i+1][j] - map_n[i][j]);
    			i++;
    		}
    		p++;
    	}

    	if(temp <= bcost)
    	{
    		bcost = temp;
    		for(int k{}; k < 2*(n-1); k++)
    		{
    			if(permutation[q] == 'r')
    			{
   					bestway[q] = 'r';
    			}
    			else
    			{
    				bestway[q] = 'd';
    			}
    			q++;
    		}
    	}

  	} while ( std::next_permutation(permutation, permutation + (2*(n-1))));

  	std::cout << "the best cost is: " << bcost << std::endl;
}

void Map::showbRoute()
{
	int i{};
	int j{};
	int p{};
	for(int k{}; k < 2*(n-1); k++)
    {
    	if(bestway[p] == 'r')
    	{
   			map_br[i][j+1] = '#';
   			j++;
    	}
   		else
 		{
    		map_br[i+1][j] = '#';
    		i++;
    	}
    	p++;
    }

    for(int i{}; i < n; i++)
	{
		for(int j{}; j < n; j++)
		{
			std::cout << map_br[i][j] << " " ;
		}
		std::cout << std::endl;
	}
}

Map::~Map()
{

	for(int i{}; i < n; i++)
	{
		delete[] map_n[i];
		delete[] map_r1[i];
		delete[] map_r2[i];
		delete[] map_br[i];
	}

	delete[] map_n;
	delete[] map_r1;
	delete[] map_r2;
	delete[] map_br;
	delete[] permutation;
	delete[] bestway;
}