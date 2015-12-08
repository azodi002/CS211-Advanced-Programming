/*
Compiler: g++
How to Compile: g++ lab7.cpp or g++ lab7.cpp -o lab7
How to run: ./a.out or ./lab7

Goal of Program: Output information about Tenure Track Professor and an Adjunct Professor
What I learned: Inheritance, const functions in classes, member initialization list
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


class CompSciProfessor
{
protected:
  string name;
  string email;
  long facultyId;

public:
  CompSciProfessor();
  void setCS(string n, string e, long i);
};

CompSciProfessor::CompSciProfessor()
{
  name=email="Unknown";
  facultyId=0;
}

void CompSciProfessor:: setCS(string n, string e, long i)
{
  name=n;
  email=e;
  facultyId=i;
}

//____________________________________________________________________________________


class AdjunctProf: public CompSciProfessor
{
protected:
  char degree;//B,M,P
  int NoOfTA;
  int NoOfCourses;

public:
  AdjunctProf();
  void setAP(string n, string e, long i, char deg, int ta, int c);
  void print() const;
  float findSalary() const;

};


AdjunctProf::AdjunctProf()
{
  degree='B';//Lowest possibility
  NoOfTA=0;  NoOfCourses=0;
}

void AdjunctProf:: setAP(string n, string e, long i, char deg, int ta, int c)
{
  CompSciProfessor::setCS(n, e, i);
  degree=deg;
  NoOfTA=ta;
  NoOfCourses=c;
}


void AdjunctProf:: print() const
{
  cout << "Degree: " << degree << endl;
  cout << "Number of TA: " << NoOfTA << endl;
  cout << "Number of Courses: " << NoOfCourses << endl;
  cout << "Name: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "Faculty ID: " << facultyId << endl;
}

float AdjunctProf:: findSalary() const
{
  float result=0.0;

  if(degree=='B')
    {
      result= (NoOfTA*1500)+(NoOfCourses*3000);
      //return result;
    }
  if(degree=='M')
    {
      result= (NoOfTA*2000)+(NoOfCourses*4000);
      //return result;
    }
  if(degree=='P')
    {
      result = (NoOfTA*2500)+(NoOfCourses*5000);
      //return result;
    }

  return result;
}


//____________________________________________________________________________________

class TenureTrackProf: public CompSciProfessor
{
protected:
  char rank;//A,S,F
  int YearOfExp;

public:
  TenureTrackProf();
  void setT(string n, string e, long i, char ranking, int exp);
  void printTen() const;
  float SalTen() const;
};

TenureTrackProf::TenureTrackProf()
{
  rank='A';//Lowest Possibility
  YearOfExp=0;
}


void TenureTrackProf:: setT(string n, string e, long i, char ranking, int exp)
{
  CompSciProfessor::setCS(n, e, i);
  ranking=rank;
  YearOfExp=exp;
  
}

void TenureTrackProf:: printTen() const
{
  cout << "Name: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "Faculty Id: " << facultyId << endl;
  cout << "Ranking: " << rank << endl;
  cout << "Years of experience: " << YearOfExp << endl;
}

float TenureTrackProf:: SalTen() const
{
  float result=0.0;
  if(rank=='A')
    {
      result=(65000)+(1500*YearOfExp);
    }
  
  if(rank=='S')
    {
      result=(80000)+(1500*YearOfExp);
    }

  if(rank=='F')
    {
      result=(90000)+(1500*YearOfExp);
    }

  return result;
}

    
//____________________________________________________________________________________



int main()
{
  AdjunctProf S1;
  S1.setAP("Adam Smith", "asmith@csusm.edu", 12345, 'M', 1, 2);
  cout<< "Salary is: " << S1.findSalary() << endl;
  S1.print();
  //_____________________________________________________________
  cout << endl;
  cout << "______________________________";
  cout << endl;
  TenureTrackProf S2;
  S2.setT("Jim Anderson" , "janderson@csusm.edu", 54321, 'A', 8);
  cout << "Salary is: " << S2.SalTen() << endl;
  S2.printTen();
  //_____________________________________________________________


  return 0;
}





