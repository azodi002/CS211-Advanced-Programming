#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class List
{
private:
  vector<T> datastore;
public:
  List()
  {

  }

  void add(T item)
  {
    datastore.push_back(item);
  }

  void display()
  {
    for(int i=0; i<datastore.size(); i++)
      {
	cout << datastore[i] << endl;
      }
  } 

};//End of class definition 

int main()
{
  List<string> grocery;
  
  grocery.add("Celery");
  grocery.add("Eggs");
  grocery.add("Bread");
  grocery.add("Milk");
  grocery.add("Chicken");
  grocery.add("Wheat");
  grocery.add("Oreoes");
  grocery.add("Peanut Butter");
  grocery.display();
  cout << "*******************************" << endl;

  List<int> grades;
  
  grades.add(89);
  grades.add(85);
  grades.add(100);
  grades.add(44);
  grades.display();

  return 0;
}
