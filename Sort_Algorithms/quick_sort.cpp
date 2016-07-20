#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(int arr[], int size)
{
  for(int i = 0; i<size; i++)
    {
      cout << arr[i] << ", ";
    }
  cout << endl;
}

void quickSort(int arr[], int left, int right)
{
  int i = left;
  int j = right;
  int tmp;
  int pivot = arr[(left+right)/2];
  
  while(i<= j)
    {
      while(arr[i] < pivot)
	{
	  i++;
	}
      while(arr[j] > pivot)
	{
	  j--;
	}
      
      if(i <= j)
	{
	  tmp = arr[i];
	  arr[i] = arr[j];
	  arr[j] = tmp;
	  i++;
	  j--;
	}
    }
  if(left<j)
    {
      quickSort(arr,left,j);
    }
  
  if(i <right)
    {
      quickSort(arr,i, right);
    }

}//End function


int main()
{
  const int size = 20;
  int numbers[size];
  srand( (unsigned) time(0));


  for(int i = 0; i<size; i++)
    {
      numbers[i] = (rand()%100) + 1;
    }

  cout << "UNSORTED: " << endl;
  display(numbers,size);
  
  cout << endl;
  cout << "SORTED: " << endl;
  quickSort(numbers, 0, size-1);
  display(numbers,size);
      


  return 0;
}
