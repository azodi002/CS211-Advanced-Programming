#include <iostream>//Used for cin and cout 
#include <string>//Used for string datatype
#include <cctype>//Used for tolower function
#include <vector>//Used for vector datatype and its functions (push_back)
#include <cstdlib>//Used for exit keyword
#include <fstream>//Used for ifstream and ofstream keywords (I/O) of files
using namespace std;//Preventing us from using std:: 

void toLower(string& makeLower)//Function that converts string to lowercase 
{//Start of function
   for(int i=0; i<makeLower.length(); i++) //start from 0 and go up till the length of the string (Increment by 1 loop)
  {
    makeLower[i] = tolower(makeLower[i]);//getting the character of the string and using the pre-made function tolower from the cctype library
  }
}//End of function

class Cryptography
{
private://Private members of class Cryptography
  vector<string> OriginalFile;//Reads data from file
  vector<string> EncryptvecusingRot;//Encrypting the file using rotation
  vector<string> Encryptvecusingcrypto;//Encrypting the file using crypto
  vector<string> DecryptvecusingRot;//Decrypting the file using rotation
  vector<string> Decryptvecusingcrypto;//Decrypting the file using crypto
  
public://Public methods of class Cryptography
  void driver();//Takes no parameters and is of type void, asks user what method they would like to use, and also when they want to exit the program, this is only method called in main
  void placeoriginalFileIntoVec();//Takes no parameters and is of type void, and reads data from the original file 
  void EncusingRot(int RotNo);//Takes one parameter(user input of rotation), and is of type void, and rotates the data read, by the number entered by the user (adds rotation number)
  void decryptusingRot(int RotNo);//Takes one parameters(user input of rotation), and is of type void, and rotates the data read, by the number entered by the user (subtracts rotation number) *Should have same output as original.txt*
  void encusingcrypto();//Takes no parameters, and is of type void, encrypts the data read from the original file using crypto, the crypto string is read in from another file
  void decusingcrypto();//Takes no parameters, and is of type void, decrypts the data read from the original file using crypto, the crypto string is read in from another file 
  void finalCrypt();//Prints out the encrypted text using crypto to output file (Encrypt02.txt) of type void, no parameters
  void finalROT();//Prints out the encrypted text using rotation to output file (Encrypt01.txt) of type void, no parameters
  void finalDecrypt();//Prints out the decrypted text using rotation to output file (Decrypt01.txt), This should match original.txt of type void, no parameters
  void printCryptoDec();//Prints out the decrypted text using crypto, output file (Decrypt02.txt), This should match original.txt of type void, no parameters

};

void Cryptography:: placeoriginalFileIntoVec()//Void function, taking no parameters, returns nothing, user will create input file and also read in file data
{//Start of function
  cout << "What is the name of the original file: ";//Prompt to console user question
  string FileName;//Used to get userinput of input file name
  cin >> FileName;//Reads input file name from user
  ifstream fin;//Creating input file variable 
  fin.open(FileName.data());//opening input file with user input name
  string word;//used to read the data from input file
  while(fin>>word)//while there is a word to be read, enter the loop
    {
      OriginalFile.push_back(word);//After word is read, store into vector and push back
    }
}//End of function


//Takes one parameter(user input of rotation), and is of type void, and rotates the data read, by the number entered by the user (adds rotation number)
void Cryptography:: EncusingRot(int RotNo)
{//Start function
  string word;//Used to get each letter from the original input file

 cout << endl;
 for(int i=0; i<OriginalFile.size();i++)
    {//Start outer for loop
      word = OriginalFile[i];//word gets the value of each letter inside the input file
      toLower(word);//User-defined function that makes the string lowercase 
      
      for(int k=0; k<word.size();k++)
	{//Start second for loop
	  
	  int ch = word[k];//Stores the letter of the string into an integer variable (Basically Ascii value)
	  if(ch>='a' && ch <= 'z')//If the ascii value is greater than or equal to ascii value of 'a' and less than or equal to ascii value of 'z'
	    {
	      if(ch+RotNo >'z')//If out of range
		{
		  ch=ch-26;//Subtracts 26 from the ascii value, to get back into range and into the alphabet
		}
	      ch = ch + RotNo;//Adds the rotation number to the original ascii value
            }
	 
	  word[k]=ch;//Store the ascii value into the element of the word(string)
	}//Close second for loop
      EncryptvecusingRot.push_back(word); //Pushes back the content of word into the vector
   }//Close outer for loop
}//End of function

//Takes one parameter(user input of rotation), and is of type void, and rotates the data read, by the number entered by the user (adds rotation number)
 void Cryptography:: decryptusingRot(int RotNo)
 {//Start function
   string word;//Used to get one character at a time from the data file read in from original.txt

   cout << endl;
   for(int i=0; i<OriginalFile.size();i++)
     {//Start outer for loop
       word = OriginalFile[i];//Stores character read from the original.txt to word
       toLower(word);//User-defined function that lowercases the string

       for(int k=0; k<word.size();k++)
	 {//Start second for loop
	   int ch = word[k];//Stores ascii value into ch
	   ch=ch-RotNo;//Subtracts from the ascii value the rotation number entered by the user

	   if(ch > 'z')//If ascii value is above 'z' 
	     {
	       ch = ch - 26;//Subtract 26 to get back into the alphabet and back into range
	     }
	   if(ch< 'a')//If ascii value is less than 'a'
	     {
	       ch=ch+26;//Add 26 to get back into the alphabet and back into range
	     }	     
	   word[k]=ch; // Stores the ascii value into the element of the word 
	 }//Close second for loop
       DecryptvecusingRot.push_back(word);//Pushes the content of the word into the vector
     }//Close outer for loop

}//Close function 

//Takes no parameters, and is of type void, encrypts the data read from the original file using crypto, the crypto string is read in from another file
void Cryptography:: encusingcrypto()
{//Start function
  
  ifstream inFile;//Variable for input file
  inFile.open("Cryptogram.txt");//Opening input file that stores the crypto string that is already given to us from the instructions
  string cryptostg;//Stores the string for the crypto code that is inside the file Cryptogram.txt 
  for(int j=0; j<26; j++)
    {
      //Don't necessarily need for loop, but either way it will override everytime it loops, therefore getting only the last string that is read
      //Did this so if I want to read character by character then it can work to
      inFile>>cryptostg;//Reads in the string from the input file Cryptogram.txt
    }

  string word;//Used to get one character at a time from the original file
  
  for(int i=0; i<OriginalFile.size();i++)
  {//Start outer for loop
    word= OriginalFile[i];//Stores the character of the original file into the variable word
    toLower(word);//User-defined function that makes the string lowercase
      for(int k=0; k<word.size();k++)
	{//Start inner for loop
	  int ch;
	  ch=word[k];   
	  if((ch>='a') && (ch<='z'))
	    {//Start if statement
	      int index = ch-'a';
	      word[k] = cryptostg[index];
	    }//End if statement
	}//Close inner for loop
      Encryptvecusingcrypto.push_back(word);
  }//Close outer for loop
}//Close function

//Takes no parameters, and is of type void, decrypts the data read from the original file using crypto, the crypto string is read in from another file
void Cryptography:: decusingcrypto()
{//Start of function
  string cryptostg;//Used to get crypto code from input file
  ifstream inFile;//Variable that reads data from a file
  inFile.open("Cryptogram.txt");//Opening a input file named Cryptogram.txt
  string word;//Used to get each character from the data read in
  char finding;

  inFile>>cryptostg;//Reading in a string of 26 characters from an input file
    

  for(int i=0; i<OriginalFile.size();i++)//Start at 0, while less than the file, incremental
    {//Start of outter loop
      word=OriginalFile[i];
      for(int j=0;j<word.size();j++)
	{//Start of inner loop
	  int ch = word[j];//Stores the ascii value of the 
	  if(ch>='a' && ch<= 'z')//If in range of alphabet lowercase
	    {
	      finding=cryptostg.find(ch,0);//Find the ascii value of the crypto string starting at 0
	      word[j]=finding+'a';//add the index to the ascii value of a, to decrypt using crypto, adding 'a' gets you to the alphabet+ the index
	    }
	}//End of inner loop
      Decryptvecusingcrypto.push_back(word);//Pushes the contents of word into the vector
    }//End of outter loop
}//End of function


//Prints out results of encryption using crypto
void Cryptography:: finalCrypt()
{
  ofstream outfile;//Output file variable name
    outfile.open("Encrypt02.txt");//Must use this output file name
  
    for(int i=0;i< Encryptvecusingcrypto.size();i++)
      {
	outfile<< Encryptvecusingcrypto[i] << " ";
	
      }
}
//Prints out results of encryption using rotation
void Cryptography:: finalROT()
{
    ofstream outfile;
    outfile.open("Encrypt01.txt");//Must use this output file name
  
     for(int i=0;i<EncryptvecusingRot.size();i++)
       {
         outfile<< EncryptvecusingRot[i] << " ";
         
      }
}

//Prints out the results of decryption using rotation
void Cryptography:: finalDecrypt()
{

  ofstream outfile;
  outfile.open("Decrypt01.txt");//Must use this output file name

  for(int i=0;i<DecryptvecusingRot.size();i++)
    {
      outfile<< DecryptvecusingRot[i] << " ";

    }
}

//Prints out the results of the decryption using crypto
void Cryptography:: printCryptoDec()
{
  ofstream outfile;
  outfile.open("Decrypt02.txt");//Must use this output file name
  
  for(int i=0;i<Decryptvecusingcrypto.size();i++)
    {
      outfile<<Decryptvecusingcrypto[i]<< " ";
    }
}



//Driver controls whole program, only function that will be called in main, of type void, no parameters, will instruct user in what to do throughout and will assist which methods of encryption and decryption they will use
void Cryptography:: driver()
{
  int choice=0;//Used for user input for encryption or decryption
  int choice2=0;//Used for second questions inside the switch statements
  cout << "Enter 1 for encryption: " << endl;
  cout << "Enter 2 for decryption: " << endl;
  cout << "Enter 3 to exit program: " << endl;
  cin >> choice;//User input of encryption or decryption
  int Rotation=0;//Used for user input of rotation number
  string cryptostg;

  if(choice==3)//Termination of program
    {
      exit(1);//Exit key-word from #include<cstdlib>
    }
  //While the user enters 1 or 2
  while(choice==1 || choice == 2)
    {
      //Reseting the vectors
      OriginalFile.clear();
      EncryptvecusingRot.clear();
      Encryptvecusingcrypto.clear();
      DecryptvecusingRot.clear();
      Decryptvecusingcrypto.clear();


  
  switch(choice)//Checks user input for encryption or decryption
    {//Start of switch
    case 1:
      //Asks which type of encryption
      cout << " Enter 1 for Encrypt by rot, 2 for encrypt by crypto: ";
      cin>> choice2;
      if(choice2==1)//User wants encryption by rotation
	{
	  placeoriginalFileIntoVec();
	  cout << "Enter in rotation number: ";//Question to user
	  cin >> Rotation;//Rotation number input from user
	  EncusingRot(Rotation);  
	  finalROT();
        }

      if(choice2==2)//User wants encryption by crypto
	{
	  placeoriginalFileIntoVec();
	  encusingcrypto();
	  finalCrypt();
	}

      break;

    case 2: 
      cout << " Enter 1 for decrpyt by rot, 2 for decrypt by crypto: ";
      cin>>choice2;//Whether use wants decryption by rotation or crypto
      
      if(choice2==1)//User wnats decryption by rotation
	{
	  placeoriginalFileIntoVec();
	  cout << "Enter in rotation number: ";//Question to user 
          cin >> Rotation;//Rotation number input from user
	  decryptusingRot(Rotation);         
	  finalDecrypt();

	}
      if(choice2==2)//User wants decryption by crypto
	{
	  placeoriginalFileIntoVec();
	  decusingcrypto();
	  printCryptoDec();
	}

      break;
    default: cout<< "Invalid input" << endl;//If user does not enter 1,2, or 3
    }//End of switch
  /*Ask questions again and get user input for 1,2, or 3, to go back into the while-loop*/
  cout << "Enter 1 for encryption: " << endl;
  cout << "Enter 2 for decryption: " << endl;
  cout << "Enter 3 to exit program: "<< endl;
  cin >> choice;//User input of encryption or decryption

}//End of While-loop
}//End of function
int main()
{
  Cryptography S1;//Making an object called S1 of type Cryptography
  S1.driver();//The object calls the method of the class that does everything

  return 0;
}
