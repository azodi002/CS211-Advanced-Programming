#include <iostream>
#include <deque>

using namespace std;

//deque stands for double ended queue
//Allow insertion front, and back

int main()
{

  deque<string> line;
  
  //To add items 
  line.push_back("Customer 1");
  line.push_front("Customer 2");
  line.push_back("Customer 3");

  cout << "Size of line: " << line.size() << endl;
  //Can access each item in the deque through an index
  
  for (int i = 0; i<line.size(); i++)
    {
      cout << line[i] << endl;
    }

  //To remove from a deque can use 2 functions:
  cout << "Removing back and front in deque" << endl << endl;
  line.pop_back();
  line.pop_front(); 
  
  
  cout << "Size of line: " << line.size() << endl;
  for(int i = 0; i<line.size(); i++)
    {
      cout << line[i] << endl;
    }



  return 0;
}
