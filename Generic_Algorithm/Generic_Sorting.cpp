#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
void display(vector<T> my_vector)
{
  for(int i = 0; i<my_vector.size(); i++)
    {
      cout << my_vector[i] << " ";
    }
  cout << endl;
  cout << endl;
}



int main()
{

  const int sizeNumbers = 10;
  
  int numbers[] = {10,1,9,2,8,3,7,4,6,5};
  
  vector<int> nums(numbers,numbers+sizeNumbers);
  display(nums);
  
  cout << "Sorting vector" << endl;
  sort(nums.begin(), nums.end());
  display(nums);

  const int size = 8;
  string words[] = {"now", "is", "the", "time", "for", "all", "good", "people"};

  vector<string> sentence(words, words+size);

  display(sentence);
  sort(sentence.begin(), sentence.end());
  cout << "Sorting sentence vector: " << endl;
  display(sentence);

  return 0;
}
