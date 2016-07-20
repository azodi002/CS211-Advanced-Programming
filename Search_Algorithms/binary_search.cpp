#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>//sort on vector

using namespace std;

//Binary search: useful for larger data set (takes SORTED set of data, divides in half each iteration)

//Linear search: degrades in performance as data set is larger


int binarySearch(vector<int> vec, int key)
{
  int first = 0;
  int last = vec.size() - 1; //end of vector

  while(first <= last)
    {
      int mid = (first + last)/2;
      if (key > vec[mid])
	{
	  first = mid + 1;
	}
     
      else if (key < vec[mid] )
	{
	  last = mid - 1;
	}
      
      else
	{
	  return mid;
	}
    }

  return -999;
}


int main()
{

  vector<int> numbers;
  //srand( (unsigned)time(0) );
  
  for(int i = 0; i<20; i++)
    {
      numbers.push_back( (rand() % 100)+1 );
    }
  
  sort(numbers.begin(), numbers.end());
  for(int i = 0; i <numbers.size(); i++)
    {
      cout << numbers[i] << ", ";
    }
     

  cout << endl;
  int key; 
  cout << "Enter number to search for: ";
  cin >> key;
  
  int return_value_binarySearch = binarySearch(numbers, key);
  
  if(return_value_binarySearch != -999)
    {
      cout << "Found number at: " << return_value_binarySearch << endl;
    }
  
  else
    {
      cout << "Number not found. " << endl;
    }
   

  return 0;
}
