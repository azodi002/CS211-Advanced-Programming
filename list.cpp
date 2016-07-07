#include <iostream>
#include <list>

using namespace std;

int main(void)
{
  list<string> names;
  names.push_back("Mary");
  names.push_back("Zach");
  names.push_back("Elizabeth");
  
  list<string>::iterator iter = names.begin();
  
  while(iter != names.end())
    {
      cout << *iter << endl;
      iter++;
    }

  cout << endl << "First item: " << names.front() << endl;
  cout << "Last item: " << names.back() << endl << endl;


  cout << "Reversing list..... " << endl << endl;
  names.reverse();

  list<string>::iterator reverse_iter = names.begin();
  
  while(reverse_iter != names.end())
    {
      cout << *reverse_iter << endl;
      reverse_iter++;
    }


  cout << "Sorting list ..... " << endl << endl;
  names.sort();
  
  list<string>::iterator sorted_iter = names.begin();

  while(sorted_iter != names.end())
    {
      cout << *sorted_iter << endl;
      sorted_iter++;
    }



  return 0;
}
