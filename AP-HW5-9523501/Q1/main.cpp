#include <iostream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>

int main()
{
	std::vector<int> vec1(100), vec2(10);

	//A.
	//Using std::iota to fill the vectors with sequential numbers starting from 1
	std::iota(vec1.begin(), vec1.end(), 1);
	std::cout << "The vector vec1 contains : \n";
	std::copy(vec1.begin(), vec1.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::iota(vec2.begin(), vec2.end(), 1);
	std::cout << "The vector vec2 contains : \n";
	std::copy(vec2.begin(), vec2.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
//----------------------------------------------------------------------------------------------------------

	//B.
	//Inserting vec1 at the end of vec2
	vec2.insert(vec2.end(), vec1.begin(), vec1.end());
	std::cout << "The vector vec2 contains : \n";
	std::copy(vec2.begin(), vec2.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

//----------------------------------------------------------------------------------------------------------

	//C.
	//Finding the number of odd values in vec1
	int odd_size{ static_cast<int>(std::count_if(vec1.begin(), vec1.end(), [](int& a) {return a % 2 == 1;})) };
	std::vector<int> odd_vec(odd_size);

	//Finding the odd numbers in vec1 using a lambda function and filling the odd_vec with them
	std::copy_if(vec1.begin(), vec1.end(), odd_vec.begin(), [](int& a) {return a%2 == 1;});
	std::cout << "The vector odd_vec contains : \n";
	std::copy(odd_vec.begin(), odd_vec.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

//----------------------------------------------------------------------------------------------------------

	//D.
	std::vector<int> reverse_vec(vec1.rbegin(), vec1.rend());
	std::cout << "The vector reverse_vec contains : \n";
	std::copy(reverse_vec.begin(), reverse_vec.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
//----------------------------------------------------------------------------------------------------------

	//E.
	std::vector<int> original(vec2);
	std::sort(vec2.begin(), vec2.end());
	std::cout << "The vector vec2 after normal sorting contains : \n";
	std::copy(vec2.begin(), vec2.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	vec2 = original;
	
}
