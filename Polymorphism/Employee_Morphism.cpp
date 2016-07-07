#include <iostream>
#include <string>
#include <sstream>//string stream
#include <vector>
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

  /*Compiler will look at function, and determine which code to run based on type of object*/
  virtual double grossPay(int hours) //Function is polymorphic
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

    virtual double grossPay(int hours)
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
  Employee emp1("Jones", 25.00);
  Manager mgr1("Smith", 1200, true);

  Employee* empPtr;
  empPtr = &emp1;
  
  cout << "Name: " << empPtr-> getName() << endl;
  cout << "Pay: " << empPtr-> getPay() << endl;

  empPtr = &mgr1; //Pointer to employee is going to call grossPay of employee.
  
  cout << "Name: " << empPtr-> getName() << endl;
  cout << "Pay: " << empPtr-> grossPay(40) << endl;


  vector<Employee*> employees;
  
  employees.push_back(&emp1);
  employees.push_back(&mgr1);
  
  for(int i=0; i<employees.size();i++)
    {
      cout << "Name: " << employees[i] -> getName() << endl;
      cout << "Pay: " << employees[i] -> grossPay(40) << endl;
    }


  return 0;
}

