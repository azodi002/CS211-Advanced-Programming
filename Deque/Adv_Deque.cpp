#include <iostream>
#include <deque>

using namespace std;



bool find(deque<string> d, string value_to_find);

int main(void)
{
  deque<string> line;
  line.push_back("David");
  line.push_back("Raymond");
  line.push_back("Cynthia");
  line.push_back("Brian");
  line.push_back("Jennifer");

  string user_enter_name = "";
  cout << "Enter name to find: ";
  cin >> user_enter_name;
  
  bool found_or_not_found;
  
  found_or_not_found = find(line, user_enter_name);
  
  if (found_or_not_found == true)
    {
      cout << "The name " << user_enter_name << " was found in deque" << endl;
    }

  else
    {
      cout << "The name " << user_enter_name << " was NOT found in deque" << endl;
    }

  deque<string>::iterator iter = line.begin(); //Currently at index 0
  ++iter; //To insert name at second position (index 1)
 
  cout << "Donnie being added to 2nd position in the line" << endl;
  line.insert(iter,"Donnie");
  
  cout << "Printing the people in line" << endl;
  for(iter = line.begin(); iter< line.end(); iter++)
    {
      cout << *iter << endl;
    }




  return 0;
}

bool find(deque<string> d, string value_to_find)
{
  for (int i = 0; i < d.size(); i++)
    {
      if (d.at(i) == value_to_find)
	{
	  return true;
	}
    }
  return false;
}

	  //At takes integer as argument and returns value stored at that position
