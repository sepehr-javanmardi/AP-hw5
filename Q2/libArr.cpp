#include <iostream>
#include "libArr.h"

long int libArr::counter(long int n)
{
  int arr[n]{};
  long int sum{};
  
  for(long int i{0} ; i<n ;i++)
    {
        arr[i]=i;
		sum += i;
    }
  
  return sum;

}
