#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int linearSearch(int arr[], int size, int key)
{
  for(int i = 0; i<size; i++)
    {
      if(arr[i] == key)
	{
	  return i;
	}
    }
  return -1;
}


int main()
{
  srand((unsigned)time(0));
  

  const int size = 20;
  int numbers[size];
  
  for(int i= 0; i<size; i++)
    {
      numbers[i] = (rand() % 100) + 1;
      cout << numbers[i] << " ";
    }
  
  int key =0;
  cout << "Enter a key: ";
  cin >> key;
  
  int result_linear_search = linearSearch(numbers, size, key);
  
  if(result_linear_search == -1)
    {
      cout << key  <<  " NOT FOUND " << endl;
    }
  
  else 
    {
      cout << key << " is at position " << result_linear_search << endl;
    } 
  
  

  return 0;
}
