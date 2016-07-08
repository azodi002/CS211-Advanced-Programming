#include <iostream>
#include <set>

//Eliminate from set all non-prime numbers

using namespace std;

void PrimeGen(int n)
{
  set<int> primes;
  int count;
  
  for(int nums = 2; nums<= n; nums++)
    {
      primes.insert(nums);
    }

  set<int>::iterator iter = primes.begin();

  for(int mults = 2; mults*mults<= n; mults++)
    {
      iter = primes.find(mults);
      if (iter != primes.end())
	{
	  for(int k = 2*mults; k<= n; k+= mults)
	    {
	      iter = primes.find(k);
	      if(iter != primes.end())
		{
		  primes.erase(*iter);
		}
	    }
	}
    }

  count = 1;
  
  for(set<int>::iterator iter2 = primes.begin(); iter2 != primes.end(); iter2++)
    {
      cout << *iter2 << " ";
      if (count ++ %10 == 0)
	{
	  cout << endl;
	}
    }

}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  PrimeGen(n);



  return 0;
}
