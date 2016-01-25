#include <iostream>
#include <fstream> 
#include <string>
#include <cstdlib>


using namespace std;


class TheMatrix;

// Function Prototype Section
ostream& operator <<(ostream& os, const TheMatrix& myMatrix);
TheMatrix  operator/ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix  operator- (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix  operator+ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix  operator* (const TheMatrix& M1, const TheMatrix& M2);
ifstream&   operator>> (ifstream& is, TheMatrix& myMatrix); 


class TheMatrix
{

public:
  int M[5][5];
 
  TheMatrix();
  ~TheMatrix();
};


//Destructor

TheMatrix:: ~TheMatrix()
{
  //Do Nothing
}

//Default Constructor

TheMatrix::TheMatrix()
{
  for(int i = 0; i < 5; i++)
    {
      for(int j = 0; j < 5; j++)
	{
	  M[i][j] = 0;
	}
    }
}

ifstream& operator>> (ifstream& is, TheMatrix& myMatrix)
{
  string fileName;
  
  cout << "Enter the file: ";
  cin >> fileName;

  is.open(fileName.data()); //Open file that user named
  
  for(int i = 0; i <5; i++)//M[5][5]
    {
      for(int j = 0; j <5; j++)
	{
	  is >> myMatrix.M[i][j];	  
	}
    }
  
  return is;
}

ostream& operator <<(ostream& os, const TheMatrix& myMatrix)
{

  for(int i = 0; i < 5 ; i++)
    {
      for(int j = 0; j < 5; j++)
	{
	  os << myMatrix.M[i][j] << " ";
	}
      os << endl;
    }
  return os;
}


TheMatrix  operator+ (const TheMatrix& M1, const TheMatrix& M2)
{
  
  TheMatrix Result; //What we will be returning

  for(int i =0; i<5; i++)
    {
      for(int j =0; j<5; j++)
	{
	  Result.M[i][j] = M1.M[i][j] + M2.M[i][j];
	}
    }

  return Result;
}

TheMatrix operator- (const TheMatrix& M1, const TheMatrix& M2)
{

  TheMatrix Result;
  for(int i = 0; i < 5; i++)
    {
      for(int j = 0 ; j < 5; j++)
	{
	  Result.M[i][j] = M1.M[i][j] - M2.M[i][j];
	}
    }
  return Result;
}


TheMatrix operator* (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;

  
  for(int i =0; i< 5; i++)
    {
      for(int j=0; j<5; j++)
	{
	  Result.M[i][j] = M1.M[i][j] * M2.M[i][j];
	}
    }

  return Result;
}

TheMatrix operator/ (const TheMatrix&M1, const TheMatrix&M2)
{
  TheMatrix Result;

  for(int i = 0; i < 5; i++)
    {
      for(int j = 0; j < 5 ; j++)
	{

	  if(M2.M[i][j] == 0)
	    {
	      Result.M[i][j] = 0;
	    }
	  else
	    {
	      Result.M[i][j] = M1.M[i][j] / M2.M[i][j];
	    }
	}
    }

  return Result;
}


int main()
{

  TheMatrix A, B, AddAB, MulAB, SubAB, DivAB;
  ifstream fin1, fin2;

  fin1 >> A;
  fin2 >> B;
  
  AddAB = A + B;

  SubAB = A - B;

  MulAB = A * B;

  DivAB = A / B;

  cout << A;
  cout << endl;
  cout << B;
  cout << endl;
  cout << AddAB;
  cout << endl;
  cout << SubAB;
  cout << endl;
  cout << MulAB;
  cout << endl;
  cout << DivAB;
  cout << endl;

  return 0;
}
