#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
  T datastore[100];
  int top;//Keep track of where we are on the stack
  
public:
  Stack()
  {
    top = -1;
  }

  void push(T num)
  {
    top++;//Next open position in array
    datastore[top] = num;
  }

  T pop()
  {
    T removedItem = datastore[top];
    datastore[top] = 0;
    top--;
    return removedItem;
  }

  T peek()
  {
    return datastore[top];
  }

};


//Template specialization
template<> 
class Stack <string>
{
private:
  string datastore[100];
  int top;//Keep track of where we are on the stack

public:
  Stack()
  {
    top = -1;
  }

  void push(string word)
  {
    top++;//Next open position in array
    datastore[top] = word;
  }

  string pop()
  {
    string removedItem = datastore[top];
    datastore[top] = " ";
    top--;
    return removedItem;
  }

  string peek()
  {
    return datastore[top];
  }

};
   
int main()
{
  Stack <string> names;
  names.push("Mary");
  names.push("Omid");
  names.push("James");
  cout << names.peek() << endl;
  string popped = names.pop();
  cout << "Popped was: " << popped << endl;
  cout << names.peek() << endl;


  return 0;
}

