#include <iostream>
using namespace std;



template <typename T>
bool equals(T arg1, T arg2)
{
  return (arg1 == arg2);
}

int main(void)
{
  int x = 5;
  int y = 4;
  
  cout << equals(x,y) << "Should be false" << endl;
  
  double a = 4.55;
  double b = 4.55;
  
  cout << equals(a,b) << "Should be true" << endl;

  string word1 = "Apple";
  string word2 = "Apple";
  
  cout << equals(word1, word2) << "Should be true" << endl;
  
  word1="None";
  word2="No";
  
  cout << equals(word1,word2) << "Should be false" << endl;

  return 0;
}
