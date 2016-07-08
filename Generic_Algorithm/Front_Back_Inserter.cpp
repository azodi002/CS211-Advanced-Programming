#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


//front inserter and back inserter
template <typename T>
void display(vector<T> my_vector)
{
  for(int i = 0; i < my_vector.size(); i++)
    {
      cout << my_vector[i] << " ";
    }
  cout << endl << endl;
}

int main()
{

  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  
  vector<int> v2;
  
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);
  
  //Specify add this data at the back of this vector
  //back_inserter argument must allow push_back operator so array is not allowed

  copy(v2.begin(), v2.end(), back_inserter(v1));
  display(v1);

  //front_inserter argument must allow push_front
  
  deque<int> d1;
  d1.push_front(1);
  d1.push_front(2);
  d1.push_front(3);
  
  copy(v2.begin(), v2.end(), front_inserter(d1));
  deque<int>::iterator iter = d1.begin();
  while (iter!= d1.end())
    {
      cout << *iter << endl;
      iter++;
   }

  


  return 0;
}
