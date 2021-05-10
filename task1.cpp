//-------------------------------------------------------------------------------------------------
// Write a function that calculates the first N prime numbers and put these numbers in the
// array passed to it.
//-------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------

typedef unsigned long long uloong;

//-------------------------------------------------------------------------------------------------

//! 
//! @brief Find n primes and fill input array by them
//! 
//! @param[in] n count of primes, that should be found
//! @param[inout] arr storage for found primes. It's elements count must be equal n
void getPrimes(uloong n, uloong* arr)
{
  uloong count = 0;
  const int first_prime = 2;
  uloong last_val = first_prime; 
  while (count != n) // find n primes
  {
    bool is_prime = true; // by default assume that number is prime
    int sqrt_last_val = sqrt(last_val); // optimization way
    
    for (uloong idx = 0; idx < count; ++idx) // check only found primes 
    {
      if (last_val == first_prime) // special case for first prime
      {
        break;
      }
      else if (*(arr + idx) > sqrt_last_val) // special case for optimization
      {
        break;
      }
      else if (last_val % *(arr + idx) == 0) // divisibility check
      {
        is_prime = false;
        break; // not prime
      }
    }

    if (is_prime)
    {
      *(arr + count) = last_val;
      ++count;
    }
    ++last_val;
  }
}
//-------------------------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
  uloong n = 1000;
  uloong* arr = (uloong*)malloc(sizeof(uloong) * n);
  
  getPrimes(n, arr);

  for (uloong idx = 0; idx < n; ++idx)
    std::cout << "idx: " << idx+1 << "\t prime: " << *(arr + idx) << std::endl;

  free(arr);
  return 0;
}
//-------------------------------------------------------------------------------------------------
