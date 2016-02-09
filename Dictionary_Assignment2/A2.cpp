#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;
const int SIZE=26;

void toLower(string& makeLower)
{
  for(int i=0; i<makeLower.length(); i++)
    {
      makeLower[i] = tolower(makeLower[i]);
    }
}

class Dictionary
{
protected:
  const int maxWordsInDict;
  const int maxWordsPerFile;
  int totalWordsInDict;
  int numOfWordsInFile[SIZE];
  static bool failure;
  static bool success;

public:
  Dictionary();//Done
  Dictionary(int dictMaxWords, int fileMaxWords);//Done
  bool AddAWord(string word);//Done
  bool DeleteAWord(string word);//Done
  bool SearchForWord(string word);//Done
  bool PrintAFileInDict(string fileName);//Done
  bool SpellChecking(string fileName);//Done
  bool InsertWordsIntoDict(string fileName);//Done
  void ProcessTransactionFile();//Done
};
//********************************************************************************************

/*Initializing static variables immediately */
bool Dictionary:: failure = false;
bool Dictionary:: success = true;

Dictionary::Dictionary():maxWordsInDict(10000),maxWordsPerFile(100)
{
  totalWordsInDict=0;

  for(int i=0; i<26; i++)
    {
      numOfWordsInFile[i]=0;
      //Referring to A.txt and so on.. till Z.txt
    }
}

//*********************************************************************************************

Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords)
{
  totalWordsInDict=0;

  for(int i=0; i<26; i++)
    {
      numOfWordsInFile[i]=0;
      //Referring to A.txt and so on.. till Z.txt
    }
}
//******************************************************************************************

bool Dictionary::AddAWord(string word)
{

  toLower(word);

  if(SearchForWord(word) == success)//Ensure that the word is not already in the appropriate file
    {
      cout << "Exists Already: " << word << endl;
      cout << "________________________________" << endl;
      return failure;
    }

  if(totalWordsInDict>=maxWordsInDict)//Make sure doesn't exceed
    {
      cout << "the dictionary is full" << endl << endl;
      cout << "_____________________________" << endl;
      return failure;
    }

  if(numOfWordsInFile[word[0]-'a'] >=  maxWordsPerFile)
    {
      cout << " The particular file is full " << endl;
      return failure;
    }

  string filename="#.txt";
  ofstream fout;
  filename[0]=toupper(word[0]);
  fout.open(filename.data(),ios::app);
  fout << word << endl;

  totalWordsInDict++;//Increment Total Words in Dictionary by 1
  numOfWordsInFile[word[0]-'a']++;

  return success;

}

//*********************************************************************************************

bool Dictionary:: DeleteAWord(string word)
{
  toLower(word);

  if(!SearchForWord(word))//Ensure that the word is not already in the appropriate file
    {
      cout << "Doesn't Exist: " << word << endl << endl;
      cout <<"_____________________" << endl << endl;
      return failure;
    }

  vector<string> dict;

  string filename="#.txt";
  ifstream fin;
  string wd;
  ofstream fout;
  filename[0]=toupper(word[0]);
  fin.open(filename.data());

  while(fin>>wd)
    {

      dict.push_back(wd);
    }

  fin.close();

  bool found = false;
  for(int j=0; !found && j<dict.size();j++)
    {
      if(dict[j]==wd)
        {
          dict.erase(dict.begin()+j);
          totalWordsInDict--;
          numOfWordsInFile[word[0]-'a']--; // wd or word?
          found = true;
        }

    }

  fout.open(filename.data());

  for(int i=0;i<dict.size();i++)
    {
      fout << dict[i] << endl;
    }
  fout.close();
  return success;

}//End of function

//*************************************************************************************

bool Dictionary:: SearchForWord(string wd)
{//Start function
  ifstream fin;
  string filename="#.txt";
  filename[0]=toupper(wd[0]);
  fin.open(filename.data());
  string read;
  fin>>read;
  while(fin)
    {//Start while
      if(wd==read)
        {
          return true;
        }
      fin >> read;
    }//End while
  return false;
}//End function

//***********************************************************************************************

bool Dictionary:: PrintAFileInDict(string fileName)
{
  int i=0;
  ifstream fin;
  string wd;

  fin>>wd;

  if(fin.fail())
    {
      return failure;
    }

  while(fin.good())
    {//Start while
      cout << wd << "   ";
      i++;
      if (i%5==0)
        {
          cout << endl;
        }//End if

      fin >> wd;
    }//End while


  return success;
}//End function

//**********************************************************************************************

bool Dictionary:: SpellChecking(string fileName)
{//Start function

  ifstream fin;
  fin.open(fileName.data());
  string word;


  if(fin.fail())
    {
      return failure;
    }
  //________________________________________________________

  else if(fin.good())
    {//Start of else-if
      cout << "Mis Spelled: " << endl << endl;
      cout << "________________________________" << endl << endl;
      while(fin.good())
	{//Start while

	  fin>>word;
	  
	  if(SearchForWord(word)==failure)
	    {
	      cout << word;
	      cout << endl;
	      cout << endl;
	    }

	}//End of while

      return success;
    }//End of else-if
}//End function


//********************************************************************************

bool Dictionary:: InsertWordsIntoDict(string fileName)
{//Start function

  ifstream fin;
  fin.open(fileName.data());
  string word;

  if(fin.fail())
    {
      return failure;
    }

  else if(fin.good())
    {//Start else-if
      while(fin.good())
        {//Start while
          fin>> word;
          AddAWord(word);
        }//End while

      return success;
    }//End else-if
}
//******************************************************************************

void Dictionary:: ProcessTransactionFile()
{
  string enter;
  string command; //Transaction.txt (FIRST COLUMN)
  string word; //Transaction.txt (SECOND COLUMN)

  ifstream inFile;

  inFile.open("Transaction.txt");

  if(inFile.fail())
    {
      cout << "File does not exist";
      exit(1);
    }

  else if(inFile.good())
    {//Start of else-if

      while(inFile.good())
	{
	  inFile>> command;
	  inFile>> word;
	  
	  
	  if(command== "AddW")
	    {
	         AddAWord(word);
	    }
	  //____________________________________

	  if(command== "DeleteW")
	    {
	      DeleteAWord(word);
	    }
	  //____________________________________

	  if(command== "SearchW")
	    {
	      SearchForWord(word);
	    }
	  //____________________________________

	  if(command== "PrintF")
	    {
	      PrintAFileInDict(word);
	    }
	  //____________________________________

	  if(command== "SpellCheck")
	    {
	      SpellChecking(word);
	    }
	  //____________________________________

	  if(command== "InsertF")
	    {
	      InsertWordsIntoDict(word);
	    }

	}//End of else-if
    }//End of while
}//End of function

//************************************************************************************************

int main()
{
  Dictionary DictForCS211;
  DictForCS211.ProcessTransactionFile();

  return 0;
}


