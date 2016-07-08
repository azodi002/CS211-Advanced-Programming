#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

using namespace std;



void display (vector<int> vec)
{
  for(int i = 0; i< vec.size(); i++)
    {
      cout << vec[i] << " ";
    }
  cout << endl;

}

int genRandom()
{
  return rand() % 100 + 1;
}



int main()
{
  /*
  vector<int> numbers(10);
  
  for(int i = 0; i< numbers.size(); i++)
    {
      numbers[i] = (rand() % 100) + 1;
    }
  display(numbers);
	
  int sum = 0;
  for(int i = 0; i<numbers.size(); i++)
    {
      sum += numbers[i];
    }
  cout << "Sum is " << sum << endl;
  */


  /*Program easier to read, less likely to make mistakes (all built in), and shorter */
  srand(time(NULL));
  vector<int> numbers(10);
  generate(numbers.begin(), numbers.end(), genRandom);
  display(numbers);

  int sum = accumulate(numbers.begin(), numbers.end(), 0);
  cout << "Sum is " << sum << endl;

  return 0;
}
