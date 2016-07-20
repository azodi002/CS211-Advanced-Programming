#include <iostream>

using namespace std;


namespace minMax
{
  int min(int a, int b)
  {
    return a <= b ? a : b;
  }

  int max(int a, int b)
  {
    return a >= b ? a: b;
  }

}


namespace People
{
  class Person
  {
  private: 
    string name;
    string sex;
  public:
    Person(string names, string sexs)
    {
      name = names;
      sex = sexs;
    }
    
    string get()
    {
      return "Name is: " + name + " Sex: " + sex + "\n";
    }
  };
}

int main()
{
  
  using namespace minMax;
 
  using namespace People;

  int a = 0, b = 0;
  
  cout << "Enter 1st number: ";
  cin >> a;
  
  cout << "Enter 2nd number: ";
  cin >> b;

  cout << "Min is: " << min(a,b) << endl;
  cout << "Max is: " << max(a,b) << endl;

  Person you("Omid Azodi", "M");
  cout << you.get();
  

  return 0;
}
