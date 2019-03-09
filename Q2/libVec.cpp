#include <iostream>
#include "libVec.h"
#include <vector>

long int libVec::counter(long int n)
{
  std:: vector <long int> vec{1};
  long int sum{vec[0]};
  for(int i{0} ; i<n ;i++)
    {
      vec.push_back(i+1) ;
      sum += i;
    }
  return sum;
}
