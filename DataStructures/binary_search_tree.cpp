#include <iostream>


using namespace std;

//For Binary Tree:
//Datastructure, with root node and series of childnodes, (Left and right child only)
//Easy to find min and max values
//To find Min value: Traverse left side
//To find Max value: Traverse right side

class Node
{
public:
  string data;
  Node* left;
  Node* right;
  Node(string d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }

};


class BST
{
private:
  Node* root;
  void Insert(string data, Node* aNode);
  Node* Search(string data, Node* aNode);
  void preOrder(Node* aNode);
  void inOrder(Node* aNode);
  void postOrder(Node* aNode);

public:
  BST();
  void Insert(string data);
  Node* Search(string data);
  void preOrder();
  void inOrder();
  void postOrder();
};

BST::BST()
{
  root = NULL;
}

void BST:: Insert(string data, Node* aNode)
{
  if (data < aNode->data)
    {
      if (aNode -> left !=NULL)
	{
	  Insert(data, aNode->left);
	}
      else
	{
	  aNode->left = new Node(data);
	  aNode->left->left = NULL;
	  aNode->left->right = NULL;
	}
    }

  else if (data >= aNode->data)
    {
      if(aNode->right !=NULL)
	{
	  Insert(data, aNode->right);
	}
      else
	{
	  aNode->right = new Node(data);
	  aNode->right->left = NULL;
	  aNode->right->right = NULL;
	}
    }
}

void BST:: Insert(string data)
{
  if (root !=NULL)
    {
      Insert(data,root);
    }
  else
    {
      root = new Node(data);
      root->right = NULL;
      root->left = NULL;
    }

}

Node* BST:: Search(string data, Node* aNode)
{
  if (aNode != NULL)
    {
      if(data == aNode->data)
	{
	  return aNode;
	}
      
      if(data < aNode->data)
	{
	  return Search(data, aNode->left);
	}
      else
	{
	  return Search(data, aNode->right);
	}
    }
  else 
    {
      return NULL;
    }
}

Node* BST:: Search(string data)
{
  return Search(data, root);
}

void BST::preOrder()
{
  preOrder(root);
}

void BST::preOrder(Node* aNode)
{
  if (aNode!=NULL)
    {
      cout << aNode->data << " ";
      preOrder(aNode->left);
      preOrder(aNode->right);
    }
}

void BST:: inOrder(Node* aNode)
{
  if (aNode != NULL)
    {
      inOrder(aNode->left);
	{
	  cout << aNode->data << " ";
	  inOrder(aNode->right);
	}
    }
}

void BST:: inOrder()
{
  inOrder(root);
}


void BST:: postOrder()
{
  postOrder(root);
}

void BST:: postOrder(Node* aNode)
{
  if (aNode!=NULL)
    {
      postOrder(aNode->left);
      postOrder(aNode->right);
      cout << aNode->data << " ";
    }
}

int main()
{

  BST *btree = new BST;
  btree->Insert("Apple");
  btree->Insert("Mango");
  btree->Insert("Kiwi");
  
  cout << "*** PreOrder: *** " << endl;
  btree->preOrder();
  cout << endl << endl;

  cout << "*** InOrder *** " << endl;
  btree->inOrder();
  cout << endl << endl;

  cout <<"*** PostOrder ***" << endl;
  btree->postOrder();
  cout << endl << endl;

  return 0;
}
