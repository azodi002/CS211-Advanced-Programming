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

  cout << "Pushing front.... " << endl << endl;
  names.push_front("Barry");
 
  cout << "Removing elizabeth from the list" << endl; 
  names.remove("Elizabeth");
  list<string>::iterator new_iter = names.begin();

  while(new_iter != names.end())
    {
      cout << *new_iter << endl;
      new_iter++;
    }

  names.pop_front();
  names.pop_back();

  cout << endl << endl;
  list<string>::iterator new_iter2 = names.begin();

  while(new_iter2 != names.end())
    {
      cout << *new_iter2 << endl;
      new_iter2++;
    }


  cout << endl << "Clearing WHOLE LIST" << endl << endl;
  names.clear();
  
  if(names.empty() == true)
    {
      cout << "List is empty" << endl;
    }

  else
    {
      cout << "List is not empty " << endl;
    }


  return 0;
}
