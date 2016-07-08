#include <iostream>
#include <vector>

#include <algorithm>
#include <numeric>

using namespace std;

//Read only algorithm: Algorithm access data in data structure, but no modifications

int main()
{
  vector<int> numbers;
  for (int i = 0; i < 10; i++)
    {
      numbers.push_back(i);
    }

  int sum = 0;
  
  for(int i = 0; i<numbers.size();i++)
    {
      sum+= numbers[i];
    }
  
  cout << "Sum is : " << sum << endl;

  //Begin range and 2nd param: to end of vector, third param: Starting value : 0 -> For sum = 0
  int sum1 = accumulate(numbers.begin(), numbers.end(), 0);
  cout << "The sum using accumulate is: " << sum1 << endl;

  //Library functions preferred over user written code.

  //Accumulate can be used on strings;
  
  vector<string> words;
  words.push_back("a");
  words.push_back("man");
  words.push_back("a");
  words.push_back("plan");
  words.push_back("a");
  words.push_back("canal");
  words.push_back("panama");
  
  //Third param: call string class constructor with empty string, make sure it is not character array
  string palindrome = accumulate(words.begin(), words.end(), string(""));
  cout << palindrome << endl;

  return 0;
}
