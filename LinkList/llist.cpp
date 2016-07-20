#include <iostream>

using namespace std;


class Node
{
public:
  string data;
  Node* next;
  
 Node(string dat, Node* anext) 
  { 
    data = dat; 
    next = anext; 
  }
  

 string getData() 
  { 
    return data; 
  }


 Node *Next()
  {
    return next;
  }

 void setNext(Node *aNext)
  {
    next = aNext;
  }

};


class llist
{
public:
  Node* top;

  llist()
  {
   top = NULL;
  }

  void Append(string data)
  {
    Node* node = new Node(data, NULL);
    Node* tmp = top;
    
    if(tmp == NULL)
      {
	top = node;
	top->next = NULL;
      }

    else
      {
	while(tmp->next !=NULL)
	  {
	    tmp = tmp->Next();
	  }

	tmp->setNext(node);
      }

  }//End Fucntion


  void Delete(string data)
  {
    Node* tmp = top->next;
   

    if(top==NULL)
      {
	cout << "Link List is empty, nothing to delete" << endl;
      }

    else if(top->Next() == NULL)
      {
	if(top->getData() == data)
	  {
	    cout << "Only one node in link list" << endl;
	    cout << "Deleting the only node left, matches what you wanted to delete " << endl;
	    delete top;
	    top = NULL;
	  }
      }
	
    else
      {
        Node* tmp2 = top;
	
	while(tmp != NULL)
	  {
	    if(tmp->getData() == data)
	      {
		tmp2->next = tmp->next;
		delete tmp;
		return;
	      }
	    else
	      {
		tmp = tmp->next;
		tmp2 = tmp2->next;
	      }
	  }
      }
		
  }//End function

  
  void print()
  {
    Node* tmp = top;
    int counter = 1;

    if(tmp == NULL)
      {
	cout << "empty link list" << endl;
      }

    else if (tmp->Next() == NULL)
      {
	cout << "Only one node in list, DATA: " << tmp->getData() << endl;
      }
	

    while(tmp != NULL)
      {
	cout << "Node " << counter << ", Data: " << tmp->getData() << endl;
	counter++;
	tmp = tmp->next;
      }
    endl(cout);
  }//End function
    
};//End class


int main()
{

  llist names;
  names.Append("Omid");
  names.Append("John");
  names.Append("David");
  names.print();

  // names.Delete("John");
  // names.print();

  names.Delete("David");
  names.print();
 
  names.Delete("John");
  names.print();

  names.Delete("Omid");
  names.print();
  
  return 0;
}
