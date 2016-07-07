#include <iostream>
#include <set>


using namespace std;


int main()
{


  set<string> words;
  
  string word = "";
  
  do
    {
      cout << "Enter a word or( quit to quit): ";
      cin >> word;
      
      //Insert also sorts as input is being inserted
      words.insert(word);

    }while( word != "quit");

  set<string>::iterator iter = words.begin();

  //Repeated values only shown once in the set   
  while(iter != words.end())
    {
      cout << *iter << " ";
      iter++;
    }


  return 0;
}
