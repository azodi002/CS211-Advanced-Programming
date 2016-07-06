//*******************************************************************************************

//CS 211 - Lab 9
//Complete the program Lab09(Program).cpp and implement the routines that are not implemented
//*******************************************************************************************

/* Use the comments given in each routine to complete the following program */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Node;
typedef Node* NodePtr;

class LL;
class Node 
{
  friend class LL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr nextStudent;

public:
   Node();
  Node(int i, string name,string email,int age);
};

class LL
{
private:
  NodePtr  top;
  void destroy (NodePtr&);

public:
  LL();
  LL(const LL& source);
  ~LL();
  void insertDataFromFile();
  void print ();
  bool search (int);
  void insertAfterFirst (int id, string name, string email, int age);
  void insertBeforeFirst (int id, string name, string email, int age);
  void insertAfterLast (int id, string name, string email, int age);
  void insertBeforeLast (int id, string name, string email, int age);
  void remove (int);
  void copy (NodePtr top1, NodePtr& top2);
};

Node:: Node()
{
  //
}
Node::Node(int i, string name, string email, int age)
{
  stId=i;
  stName=name;
  stEmail=email;
  stAge=age;
}
//--------------------------------------------
//--------------------------------------------

LL::LL()//Default constructor Initializes top to null
{
  top=NULL;

}

//--------------------------------------------
//--------------------------------------------

LL::LL(const LL& source)
{

  top=NULL;
  copy(source.top,top);

 

}

//--------------------------------------------
//--------------------------------------------

LL::~LL()
{
  destroy(top);
}

//--------------------------------------------
//--------------------------------------------

void LL::insertDataFromFile()
{

  int id; 
  string name;
  string email;
  int age;
  ifstream fin;
  fin.open("transaction.txt");


  if(!fin)
    {
      cout << "The input file doesn't exist" << endl;
    }

  
  while(fin.good())
    {
      fin>>id>>name>>email>>age;
      insertAfterLast(id, name, email, age);
     
    }

}

//--------------------------------------------
//--------------------------------------------
// print the linked list

void LL::print ()
{

  NodePtr p = top;
  cout<<"------------------------------"<<endl;
  while(p != NULL)
    {
      cout<<p->stId<<"\t"
	  <<p->stName<<"\t"
	  <<p->stEmail<<"\t"
	  <<p->stAge<<endl;
      p = p->nextStudent;
    }
  cout<<"------------------------------"<<endl;

}

//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list

bool LL::search (int id)
{
  
  NodePtr p = top;

  while((p->stId != id)&&(p->nextStudent != NULL) )
    {
      p = p->nextStudent;
    }
  if((p == NULL)||((p != NULL) && (p->stId != id)))
    {
      
      return false;
    }
  
  return true;
}

//--------------------------------------------
//--------------------------------------------

void LL::insertAfterFirst (int id, string name, string email, int age)
{
  NodePtr p;
 
  if(top!= NULL)
    {
      p= new Node(id,name,email,age);
      p-> nextStudent=top->nextStudent;
      top->nextStudent = p;
    }

  else if(top==NULL)
    {
      insertBeforeFirst(id,name,email,age);
    }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertBeforeFirst (int id, string name, string email, int age)
{
  NodePtr p=new Node(id,name,email,age);
  p-> nextStudent= top;
  top=p;
}

//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10

void LL::insertAfterLast (int id, string name, string email, int age)
{
  NodePtr p = new Node(id,name,email,age);
  NodePtr q = top;
  if(top==NULL)
    {
      top=p;
      return;
    }

  if(top->nextStudent==NULL)
    {
      top->nextStudent=p;
      return;
    }

  while(q->nextStudent !=NULL)
    {
      q=q->nextStudent;
     
    }
  
   q->nextStudent=p;
}

//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6

void LL::insertBeforeLast (int id, string name, string email, int age)
{
  NodePtr p;
  NodePtr q;
  p=top;
 
  if(p->nextStudent==NULL)
    {
      insertBeforeFirst(id,name,email,age);
    }
  if(top==NULL)
    {
      insertBeforeFirst(id,name,email,age);
    }
  else
    {
  while(p->nextStudent!=NULL)
   {

     //if(p->nextStudent->nextStudent !=NULL)    
     //{
     p=p->nextStudent;   
     
   }
 q= new Node(id,name,email,age); 
 q->nextStudent= p->nextStudent;
 p->nextStudent=q;
 
    
 }//End of while 
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void LL::remove (int id)
{
  
  NodePtr p=top;
  NodePtr q;

  if(search(id)== false)
    {
      cout<<"The id doesn't exist."<<endl;
    }
  else
    {
      if(top->stId == id)
	{
	  q = top;
	  top = top ->nextStudent;
	  delete q;
	}
      else
	{
	  while(p->nextStudent->stId != id)
	    {
	      p = p->nextStudent;
	    }
	  q = p->nextStudent;
	  p -> nextStudent = q->nextStudent;
	  delete q;
	  
	}
    }


}
//--------------------------------------------
//--------------------------------------------

// copies one list into another
void LL::copy (NodePtr atop, NodePtr& btop)
{
  NodePtr acurr, bcurr;
  
  //destroy (btop); // deleted previous nodes in the list if there is any
  NodePtr p = btop;
  NodePtr q;
  while(p != NULL)
    {
      q = p;
      p = p -> nextStudent;
      delete q;
      q = p;
    }
  top = NULL;
  
  if (atop != NULL) 
    {
      btop = new Node;
      btop -> stId = atop -> stId;
      btop -> stName = atop -> stName;
      btop -> stEmail = atop -> stEmail;
      btop -> stAge = atop -> stAge;
      acurr = atop;
      bcurr = btop;


      while (acurr -> nextStudent != NULL) 
	{
	  bcurr -> nextStudent = new Node;
	  acurr = acurr -> nextStudent;
	  bcurr = bcurr -> nextStudent;
	  bcurr -> stId = acurr -> stId;
	  bcurr -> stName = acurr -> stName;
	  bcurr -> stEmail = acurr -> stEmail;
	  bcurr -> stAge = acurr -> stAge;
	}
      bcurr -> nextStudent = NULL;
    }
  


}       
//--------------------------------------------

// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{
  NodePtr p=top;
  NodePtr q=top;
  while(p != NULL)
    {
      p = p ->nextStudent;
      delete q;
      q = p;
    }
  top = NULL;

}
//--------------------------------------------

int main () 
{
  LL list1;
    list1.insertDataFromFile();
  
  list1.print();
  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();
   bool  found = list1.search (12321);
  if (found)
    cout << "the record was found" << endl;
  else
    cout << "the record was not found" << endl;
  list1.remove (54321);
  list1.print();
   
  LL list2(list1);
  list2.print();
  return 0;
  }
//--------------------------------------------
