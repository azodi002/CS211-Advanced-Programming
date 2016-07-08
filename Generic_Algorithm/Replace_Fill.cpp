#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Fill algorithm takes container with a range and fills that range with specified value
//Read-Write Algorithm

template <typename T>
void display(vector<T> my_vector)
{
  for(int i = 0; i < my_vector.size(); i++)
    {
      cout << my_vector[i] << " ";
    }
  
  cout << endl;
}


int main()
{
  vector<int> numbers;
  
  for(int i = 0; i<10; i++)
    {
      numbers.push_back(i);
    }

  display(numbers);

  //We want to zero out the vector
  cout << "Filling vector with all 0's" << endl;
  fill(numbers.begin(), numbers.end(), 0);
  display(numbers);
  cout << endl;

  vector<string> names;
  names.push_back("Jennifer");
  names.push_back("George");
  names.push_back("Adele");
  display(names);
  cout << "Filling names with all blanks " << endl;
  fill(names.begin(), names.end(), string(""));
  display(names);

  cout << "Replacing all 0's with 4's inside the vector" << endl;
  replace(numbers.begin(), numbers.end(), 0, 4);
  display(numbers);
  cout << endl;
  
  vector<string> words;
  words.push_back("gift");
  words.push_back("to");
  words.push_back("recieve");
  display(words);
  
  cout << "Look closely a mistake for the word recieve!!!!!" << endl;
  cout << "Replacing that word with the correct word ....... 99% "<< endl;
  replace(words.begin(), words.end(), "recieve", "receive");
  display(words);
  
  



  return 0;
}
