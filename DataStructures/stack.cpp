#include <iostream>
#include <string>


using namespace std;


class Stack
{
 private:
  string datastore[100];
  int top;

 public:
  Stack();
  void push(string value);
  void pop (string& value);
  string peek();
  int count();
  void clear();
  bool isEmpty();
};


Stack::Stack()
{
  top = -1;
}


void Stack:: push(string value)
{
  ++top;
  datastore[top] = value;
}

void Stack:: pop(string& value)
{
  value = datastore[top];
  --top;
}

string Stack:: peek()
{
  return datastore[top];
}

int Stack:: count()
{
  return top + 1; //Top pointing to next open element (total # of elements stored in stack
}

void Stack:: clear()
{
  for(int i = 0; i<= top-1; i++)
    {
      datastore[i] = "";
      top = -1;
    }
}

bool Stack:: isEmpty()
{
  if(top == -1)
    {
      return true;
    }
  else
    {
      return false;
    }
}


int main()
{
  Stack names;
  names.push("Mary");
  names.push("Omid");
  
  cout << "Number of items inside stack: " << names.count() << endl;
  string del_value ="";
  
  if(names.isEmpty() == false)
    {
      names.pop(del_value);
    }

  cout << "Number of items inside stack now: " << names.count() << endl;
  cout << "Clearing the stack " << endl;
  names.clear();
  cout << endl;
  cout << "Number of items inside stack now: " << names.count() << endl << endl;

  return 0;
}
