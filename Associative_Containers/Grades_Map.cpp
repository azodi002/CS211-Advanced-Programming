#include <iostream>
#include <map>

using namespace std;



int main()
{

  map<string, int> grades;
  
  grades["Omid"] = 94;
  grades["John"] = 33;
  grades["Mary"] = 22;
  
  string name = "";
  
  cout << "Enter name to find in gradebook: ";
  cin >> name;
  
  //If gets to end of map and doesn't find name passed in as argument, will be at end of map
  //Iterator based-find.
  if (grades.find(name) != grades.end())
    {
      cout << name << ": " << grades[name] << endl;
    }
  
  else
    {
      cout << name << " not found" << endl;
    }

  double average = 0.0;
  int sum = 0;
  
  map<string, int>::iterator iter = grades.begin();
  
  while(iter!= grades.end())
    {
      cout << iter->second << endl;
      sum+= iter->second; //2nd data member of that object (Remeber in pairs its first or second
      iter++; //Move to next item in the map
    }
  
  average = sum/ grades.size();
  cout << "Average grade for class is: " << average << endl;
  


  return 0;
}
