#include <iostream>
#include <utility>


using namespace std;




int main()
{

  pair<string, string> number1("Jones", "123");
  
  cout << number1.first << " : " << number1.second << endl;


  pair<string, int> student1("Omid", 93);
  cout << student1.first << " : " << student1.second << endl;

  return 0;
}
