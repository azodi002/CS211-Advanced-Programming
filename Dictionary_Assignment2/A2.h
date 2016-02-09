//Omid Azodi
//10/30/2014
//Assignment #2
//CS211
//Email: azodi002@cougars.csusm.edu
//Input files: Transaction.txt, data.txt, myEssay.txt
//Output files: N/A (Results printed to screen)
//This assignment creates a dictionary, reads in a file and then reads in another file and tells you which words are mispelled and also puts the words read 
// into Separate files for their own designated locations
//Professor: Dr.Hadaegh (CS211)

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

const int SIZE=26;//Used to initialize the array size

class Dictionary //Class named Dictionary
{
 protected://Protected members, instead of private, good practice just in case inheritance will be used
  const int maxWordsInDict;//Makes sure the dictionary is not going over the amount of words it can hold
  const int maxWordsPerFile;//Makes sure each file does not go over the amount of words it can hold
  int totalWordsInDict;//Counts total words in dictionary (Total)
  int numOfWordsInFile[SIZE];//Array with 26 elements (0-25)
  static bool failure;//Static variable that returns 0 if false/failure
  static bool success;//Static variable that returns 1 if true/success


  /*Public Functions/Constructors*/

 public:
  /*More detail about each function/constructor when implemented*/
  Dictionary(); //Default constructor initializes to the required instructions
  Dictionary(int dictMaxWords, int fileMaxWords);//Constructor that sets the parameters to the protected members of the class
  bool AddAWord(string word);//Function that returns 0,1 and takes a string in as a parameter
  bool DeleteAWord(string word);//Function that returns 0,1 and takes a string in as a parameter
  bool SearchForWord(string word);//Function that returns 0,1 and takes a string in as a parameter
  bool PrintAFileInDict(string fileName);//Function that returns 0,1 and takes a string in as a parameter
  bool SpellChecking(string fileName);//Function that returns 0,1 and takes a string in as a parameter
  bool InsertWordsIntoDict(string fileName);//Function that returns 0,1 and takes a string in as a parameter
  void ProcessTransactionFile();//Function that returns 0,1 and takes a string in as a parameter
};//End of class declaration

//********************************************************************************************

