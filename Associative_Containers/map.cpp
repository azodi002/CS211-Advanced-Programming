#include <iostream>
#include <map>

using namespace std;


int main()
{

  map <string, string> numbers;
  numbers["Jones"] = "365";
  
  numbers["Omid"] = "440";
  
  numbers["John"] = "222";

  cout << "Jones: " << numbers["Jones"] << endl;

  cout << "Number of things stored in map: " << numbers.size() << endl;

  cout << "Deleting an item in the map: " << endl;
  
  //Provide key to erase method
  numbers.erase("Omid");
  
  cout << "Number of things stored in map: " << numbers.size() << endl;
  

  return 0;
}
