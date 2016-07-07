#include <iostream>
using namespace std;


class Animal
{
public:
  virtual void talk() = 0;
};


class Dog: public Animal
{
public:
  virtual void talk()
  {
    cout << "Woof Woof" << endl;
  }
};


class Cat: public Animal
{
public:
  virtual void talk()
  {
    cout << "Meow Meow" << endl;
  }

};


int main()
{

  Dog doggy;
  Cat kitty;
  
  doggy.talk();
  kitty.talk();



  return 0;
}
