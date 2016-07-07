#include <iostream>

using namespace std;



const int DivideByZero = 1;

int main()
{
  
  try
    {
      int numerator = 12;
      int denominator = 0;
      if(denominator == 0)
	{
	  throw DivideByZero;
	}
      else
	{
	  cout << numerator/denominator;
	}
    }

  catch(int e)
    {
      if(e == DivideByZero)
	{
	  cerr << "Can't divide by zero";
	}
    }
 

  return 0;
}
