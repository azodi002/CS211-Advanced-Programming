#include <iostream>
#include <vector>


//reverse iterator allows working backwards on a container

//Container such as a vector

using namespace std;



int main()
{
  vector<int> numbers;
  
  for(int i = 0; i< 10; i++)
    {
      numbers.push_back(i);
    }
  //Forward iteration
  for(vector<int>::iterator iter = numbers.begin(); iter!= numbers.end(); iter++)
    {
      cout << *iter << " ";
    }

  cout << endl;


  //Reverse iteration
  for(vector<int>::reverse_iterator riter = numbers.rbegin(); riter != numbers.rend(); riter++)
    {
      cout << *riter << " ";
    }
  cout << endl;



  return 0;
}
