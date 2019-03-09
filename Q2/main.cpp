#include <iostream>
#include "libArr.h"
#include "libVec.h"
#include <ctime>

template<class T>
double runTime( long int (T::*)(long int) ,long int ,T);
int main()
{
  long int (libArr::*func_arr)(long int){&libArr::counter}; //for using pointer to member function
  long int (libVec::*func_vec)(long int){&libVec::counter};
  libArr arr{};
  libVec vec{};

  for(long int i{1}; i < 10000000; i = i*10) //calling class functions and print out runtime for eachs
  {
    std::cout << "the number of inputs is: " << i << std::endl;
    std::cout << "time for libArr is: " << runTime(func_arr, i, arr) << std::endl;
    std::cout << "time for libVec is: " << runTime(func_vec, i, vec) << std::endl;
    std::cout <<"---------------------------------------" << std::endl;
  }

  return 0;
}

template<class T> //runtime function with class template
double runTime( int (T::*func)(long int) ,long int n ,T a)
{
  double time{};
  std::clock_t start{};
  time = std::clock();
  (a.*func)(n);
  time = 1000*(static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
  return time;
}
