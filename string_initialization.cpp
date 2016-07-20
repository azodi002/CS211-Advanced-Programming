#include <iostream>
#include <string>

using namespace std;




int main()
{

  string str0("default");
  string str1("default2");
  
  /*Copy constructor example*/
  cout << "str 0 = " << str0 << endl;
  cout << "str1 = " << str1 << endl;
  
  string str2(str1);
  
  cout << "Using copy constructor as follows: string str2(str1);" << endl;
  cout << "str2 = " << str2 << endl;
  
  string str3("a string");
  cout << "str3 = " << str3 << endl;
  
  /* Can intialize string using number of characters of a certain kind */
  string str4(10, '*');
  cout << "str4 = " << str4 << endl;

  string str5 = "Hello";
  cout << "str5 = " << str5 << endl;

  string str6 = " World!";
  cout << "str6 = " << str6 << endl;

  string str7 = str5 + str6;
  cout << "Concatnating str5 and str6" << endl;
  cout << "str7 = " << str7 << endl;


  return 0;
}
