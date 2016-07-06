#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


int gcd(int x, int y);

int main(void)
{
  int x;
  int y;
  int result;

  cout<< "Enter x value (Enter a negative number to quit): ";
  cin>> x;

  cout << endl;

  cout << "Enter y value (Enter a negative number to quit): ";
  cin >> y;


  cout << endl;


 result= gcd(x,y);
 cout <<"GCD IS: " << result << endl;


  return 0;
}

int gcd(int x, int y)
{
 
  if(y==0)
    {
      return x;
  
    }

  else 
    {
      return gcd(y, x%y);
      
    }

  
}
