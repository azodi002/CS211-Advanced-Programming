#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int fib(int pos);
bool check(int pos);


int main(void)
{
  int result=0;
  int num=0;
  
  cout << "Enter number: (Negative number to quit) ";
  cin >> num;  
  cout << endl;
  
  while(num>=0)
    {

  result=check(num);
  if(result==1)
    {
      cout << num << " is a fibonacci number" << endl;
    }
  else if (result!=1)
    {
      cout << num << " is NOT a fibonacci number" << endl;
    }

  cout << "Enter position: (Negative number to quit) ";
  cin >> num;

   }


  return 0;
}

int fib(int pos)
{

  if(pos<=1)
    {
      return pos;
    }

  else
    {
      return fib(pos-1)+fib(pos-2);
    }

}

bool check(int num)
{

  for(int i=0; true/*i<num*/; i++)
    {
      if(fib(i)==num)
	{
	  return 1;
	}

      else if(fib(i)>num)
	{
	  return 0;
	}
    }

}


