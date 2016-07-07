#include <iostream>
#include <string>
#include <sstream>//string stream

using namespace std;


/* Base class */
class Employee
{

  //Access level is protected, and can be accessed directly by derived class
  protected:
  string name;
  double pay;


  public:

  ~Employee()
  {

  }

  Employee()
  { 
    name = "Unknown"; 
    pay = 0.0;
  }

  Employee(string empName, double payRate)
  {
    name = empName;
    pay = payRate;
  }

  /* Getter */
  string getName()
  {
    return name;
  }
  
  /* Setter */
  void setName(string empName)
  {
    name = empName;
  }

  
  /* Getter */
  double getPay()
  {
    return pay;
  }

  /* Setter */
  void setPay(double payRate)
  {
    pay = payRate;
  }


  string toString()
  {
    stringstream stm;
    stm << name << ": " << pay;
    return stm.str(); //Stream to string object      
  }

  double grossPay(int hours)
  {
    return pay * hours;
  }


};//End of Employee class definition


  // Manager class is derived from employee class
  class Manager: public Employee
  {
    private:
    bool salaried;
    
    public:

    //default constructor, BASE Constructor automatically called
    Manager():salaried(true) 
    {
      
    }
    
    Manager(string name, double payRate, bool isSalaried):Employee(name, payRate)
    {
      salaried = isSalaried;
      
    }

    //Destructor, free allocated resources, allocate memory and when object is deleted free up the memory, so no memory leak.
    ~Manager()
    {
      //Destrutor called automatically when object deleted from program
    }
    
    bool getSalaried()
    {
      return salaried;
    }

    double grossPay(int hours)
    {
      if(salaried == true)
	{
	  return pay;
	}

      else
	{
	  return pay*hours;
	}
    }

    string toString()
    {
      stringstream stm;
      string salary;

      if(salaried == true)
	{
	  salary = "Salaried";
	}
      
      else
	{
	  salary = "Hourly";
	}
      
      stm << name << ": " << pay << ": " << salary  << endl;
      return stm.str(); //Stream to string object
    }

 };//End of Manager class definition



int main()
{

  /*Test case #1*/

  /*
  Employee emp1("Jane Smith", 35000);
  Employee emp2("Bill Brown", 32000);
  cout << emp1.toString() << endl;
  cout << emp2.toString() << endl;

  cout << endl;
  cout << "Before changing " << emp1.getName() << "'s salary, her current salary is: " << emp1.getPay() << endl;
  emp1.setPay(65000);
  cout << "After changing " << emp1.getName() << "'s salary, her NEW salary is: " << emp1.getPay() << endl;
  */


  /*Test case #2*/

  Employee emp1("Mary Smith", 15.00);
  cout << "Employee name: " << emp1.getName() << endl;
  cout << "Employee pay rate: " << emp1.getPay() << endl;
  cout << "Employee gross pay: " << emp1.grossPay(40) << endl;
  
  cout << "**************************************" << endl;

  /* Test case #3 */

  /*
  Manager emp2("Bob Brown", 1500, true);
  cout << "Employee name: " << emp2.getName() << endl;
  cout << "Employee pay rate: " << emp2.getPay() << endl;
  cout << "Emp2 is salaried? " << emp2.getSalaried() << endl;
  cout << "Emp2 gross pay: " << emp2.grossPay() << endl;
  */

  Manager emp2("Bob Brown", 1500, true);
  cout << emp2.toString();
  cout << "Gross pay for emp2 is: " << emp2.grossPay(100);

  return 0;
}

