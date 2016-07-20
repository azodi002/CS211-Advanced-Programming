#include <iostream>
#include <string>


using namespace std;


int main()
{
  string s1 = "a needle in a haystack, the needle was found!";
  int pos = s1.find("needle");
  
  //Find will return position of FIRST occurence
  if (pos >= 0)
    {
      cout << "Found needle" << " at position " << pos <<   endl;
    }
  else
    {
      cout << "no Needle" << endl;
    }

  /* IF multiple occurences look for last occurence as follows: */
  
  int pos2 = s1.rfind("needle");
  
 
  if (pos2 >= 0)
    {
      cout << "Found needle" << " at position " << pos2 <<   endl;
    }
  else
    {
      cout << "no Needle" << endl;
    }

  string numbers = "0123456789";
  string identifier = "name98";
  
  int pos3 = identifier.find_first_of(numbers); 
  //any occurence in passed in string in string calling method, will return that position found
  
  if( pos3 >= 0)
    {
      cout << "illegal identifier" << endl;
    }

  else
    {
      cout << "legal identifier" << endl;
    }



  return 0;
}
