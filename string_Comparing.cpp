#include <iostream>
#include <string>


using namespace std;



int main()
{

  string s1 = "clear";
  string s2 = "cler";
  
  /* A string being greater than compares letter to letter regardless of upper or lower case */
  if(s1 > s2)
    {
      cout << s1 << " is greater than " << s2 << endl;
    }
  else
    {
      cout << s2 << " is greter than " << s1 << endl;
    }
 
  cout <<  s1.compare(s2) << endl;
 

  return 0;

}
