#include <iostream>

using namespace std;


class Queue
{
private:
  string datastore[100];
  int back;
  const static int front = 0; 
  void shift()
  {
    for(int i = front; i<=back; i++)
      {
	datastore[i] = datastore[i+1];
      }
    --back;
  }

public:
  Queue();
  void put_in(string value);
  void take_out(string& value);
  void show();
  int count();
  string qfront();
  string qback();
  bool isEmpty();
  void clear();
};


Queue::Queue()
{
  back = -1;
}

void Queue::put_in(string value)
{
  ++back;
  datastore[back] = value;
}

void Queue::take_out(string& value)
{
  value = datastore[front];
  shift();
}

void Queue:: show()
{
  for (int i = front; i <= back; i++)
    {
      cout << datastore[i] << " ";
      
    }
  cout << endl;
}

int Queue:: count()
{
  int counter = 0;
  
  for(int i = 0; i <= back; i ++)
    {
      counter++;
    }
  return counter++;
}

string Queue:: qfront()
{
  return datastore[front];
}

string Queue:: qback()
{
  return datastore[back];
}

bool Queue:: isEmpty()
{
  if (back == -1)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Queue:: clear()
{
  for(int i = front; i<= back; i++)
    {
      datastore[i] = "";
    }
}



int main()
{
  Queue letters;
  
  letters.put_in("A");
  letters.put_in("B");
  letters.put_in("C");
  
  cout << "Front of queue : " << letters.qfront() << endl;
  cout << "Back of queue: " << letters.qback() << endl;
  cout << "Number of items inside queue: " << letters.count() << endl;
  letters.show();
  
  string deleted_value ="";
  letters.take_out(deleted_value);
  letters.show();
  letters.put_in("D");
  letters.show();
  cout << "Front of queue: " << letters.qfront() << endl;
  cout << "Back of queue: " << letters.qback() << endl;
  cout << "Number of items inside the queue: " << letters.count() << endl;


  return 0;
}
