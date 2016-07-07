#include <iostream>
#include <map>
#include <utility> //pair class

using namespace std;




int main()
{

  multimap<string,string> numbers;
  //multimap allows multiple duplicate keys
  
  numbers.insert(pair<string,string>("Jones", "123"));
  numbers.insert(pair<string,string>("Smith", "245"));
  numbers.insert(pair<string,string>("Brown", "678"));
  numbers.insert(pair<string,string>("Jones", "999"));
  numbers.insert(pair<string,string>("George", "222"));
  numbers.insert(pair<string,string>("Jones", "333"));
  
  string searchName = "Jones";
  
  multimap<string,string>::iterator iter = numbers.find(searchName);
  
  //Find last occurence of jones in multimap
  multimap<string,string>::iterator last = numbers.upper_bound(searchName);
  

  for(; iter!=last; iter++)
    {
      cout << iter->first << " : " << iter->second << endl;
    }


  return 0;
}
