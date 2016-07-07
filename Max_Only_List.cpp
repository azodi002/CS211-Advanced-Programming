#include <iostream>
#include<list>
#include <deque>

using namespace std;


void display(list<int> my_list);
void insertMax(list<int>& my_list, int value);

int main(void)
{

  list<int> my_numbers; //list contains random values at initilization
  my_numbers.push_back(0); //Max value (default) so anything entered will be compared to 0

  //User enters some numbers into list
  int number = 0;

  for(int i = 0; i <10; i++)
    {
      cout << "Enter a number: ";
      cin >> number;
      insertMax(my_numbers, number);
    }

  display(my_numbers);


  return 0;
}

void display(list<int> my_list)
{
  list<int>::iterator iter = my_list.begin();
  
  while (iter != my_list.end())
    {
      cout << *iter << endl;
      iter++;
    }
}

void insertMax(list<int>& my_list, int value)
{
  my_list.sort();
  
  //Since sorted will have max value at back of list
  int max_value = my_list.back(); 
  
  //Now check value given is greater than max then we accept it into the list
  
  if(value > max_value)
    {
      my_list.push_back(value);
    }
}
