#include <iostream>
#include <string>

using namespace std;

int find(string word, char key)
{
  for(int i = 0; i< word.length(); i++)
    {
      if(word[i] == key)
	{
	  return i;
	}
    }

  return -1;
}

string replace(string word, char key, char replace)
{
  int pos = find(word, key);
  
  word = word.substr(0, pos) + replace + word.substr(pos + 1);

  return word;
}

string replace2(string word, char key, char replace)
{

  for(int i = 0; i<word.length(); i++)
    {
      if(word[i] == key)
	{
	  word[i] = replace;
	  goto label;
	}
    }
 label: return word;

}



int main()
{

  string word = "hello";
  char key = 'e';
  
  int pos = find(word, key);
  cout << pos << endl;

  string new_word = "word";
  new_word = replace(new_word, 'd', 'k');
  cout << new_word << endl;


  string word2 = "word";
  word2 = replace2(word2, 'd', 'k');
  cout << word2 << endl;

  return 0;
}
