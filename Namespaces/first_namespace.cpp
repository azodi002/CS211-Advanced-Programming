#include <iostream>
using namespace std;

//namespace is a scope, which we can place definitions, (functions, classes, variables)

namespace firstNums
{
  int num1 = 10;
  int num2 = 12;
}

namespace secondNums 
{
  int num1 = 1;
  int num2 = 2;
}



int main()
{

  cout << "num1 in firtNums is: " <<  firstNums::num1 << endl;
  cout << "num1 in secondNums is: " <<  secondNums::num1 << endl;
  
  cout << "num2 in firstNums is: " <<  firstNums::num2 << endl;
  cout << "num2 in secondNums is: " << secondNums::num2 << endl;

  {
  using namespace firstNums;
  cout << "num1 in firstNums: " << num1 << endl;
  cout << "num2 in firstNum: " << num2 << endl;
  }

  {
    using namespace secondNums;
    cout << "num1 in secondNums: " << num1 << endl;
    cout << "num2 in secondNums: " << num2 << endl;
  }


  return 0;
}
