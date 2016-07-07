#include <iostream>
#include <string>


using namespace std;

template <typename T> //T represents type

void display (T array[], int size)
{
  for(int i=0; i<size; i++)
    {
      cout << array[i] << " ";
    }

  cout << endl;
}



template <typename T>
T max(T &arg1, T &arg2)
{
  if(arg1>arg2)
    {
      return arg1;
    }
  
  else
    {
      return arg2;
    }

}

int main()
{
  /*
  const int size = 10;
  
  int numbers[size];
  
  for(int i=0; i<size; i++)
    {
      numbers[i]=i+1;
    }


  display(numbers, size);

  string names[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
  
  display(names, size);
  */

  int a = 12;
  int b = 24;
  cout << max (a,b) << endl;

  double x = 2.25;
  double y = .25;
  
  cout << max(x,y) << endl;
  
  string word1 = "apple";
  string word2 = "Dinosaur";
  
  cout << max(word1,word2) << endl;
  

  return 0;
}

