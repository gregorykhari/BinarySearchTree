//*********************************************
//
// Author: Gregory Hinkson
//
// Date Modified: 5/10/2017
// 
//*********************************************

#include <iostream>
#include "BNode.h"

//constructor for BST
BST::BST()
{
  root = NULL;
}

//returns true if tree is empty, false otherwise
bool BST::isEmpty() const
{
  return (root == NULL);
}

//returns true if value found in tree, false otherwise
bool BST::search(int key) const
{
  //if tree is empty
  if(isEmpty())
    return false;
  
  BNode * cursor = root;
  
  while(cursor != NULL)
  {
    if(cursor -> data == key)
      return true;
    if(cursor -> data > key)
      cursor = cursor -> left;
    else 
      cursor = cursor -> right;
  }
  return false;
}

void BST::insertLeaf(int value)
{
  //tree is empty, set new node to root
  if(isEmpty())
  {
    root = new BNode(value);
    return;
  }
  
  //value already exists in tree
  if(search(value))
	return;

  BNode * cursor = root;//pointer to current node
  BNode * parent = NULL;//pointer to parent of cursor

  while(cursor != NULL)
  {
	parent = cursor;
	if(cursor -> data > value)
		cursor = cursor -> left;
	else if(cursor -> data < value)
		cursor = cursor -> right;
  }

  BNode * newLeaf = new BNode(value);

  if(parent -> data > value)
	  parent -> left = newLeaf;
  if(parent -> data < value)
    parent -> right = newLeaf;
}

void BST::deleteLeaf(int value)
{
	//if tree is empty cannot delete 
	if(isEmpty())
		return;
	
	//if value does not exist in tree cannot delete
	if(!search(value))
		return;

	BNode * dNode = deleteAuxillary(root,value); //pointer to node to be deleted
 
	int min = getMinRight(dNode);//pointer to min node in right subtree of dNode
 
	BNode * minRightPtr = deleteAuxillary(root,min);//pointer to smallest value in right subtree
	
	//swap min value in right subtree with node to be deleted		
	BNode * minParent = getParent(min);
   
   
	if(minParent -> left -> data == min)
		minParent -> left = NULL;
	else 
		minParent -> right = NULL;
	
  //set value of node to be deleted to value of node in right subtree
	dNode -> data = min;

  //delete min node in right subtree
	delete minRightPtr;		
}

//returns pointer to node to be deleted
BNode * BST::deleteAuxillary(BNode * root, int value) const
{
	if(isEmpty())
		return NULL;
	
	if(root -> data == value)
		return root;
	if(root -> data > value)
		return deleteAuxillary(root -> left, value);
	else 
		return deleteAuxillary(root -> right, value);
}

//returns pointer to the smallest node in right subtree
int BST::getMinRight(BNode * root) const
{
	BNode * cursor = root -> right;
	int min;

	while(cursor != NULL)
	{
	min = cursor -> data;
	cursor = cursor -> left;
	}
	return min;
}

//returns pointer to parent of node containing value
BNode * BST::getParent(int value) const
{
	BNode * parent = root;
	
	for(;;)
	{
		if(parent -> left -> data == value || parent -> right -> data == value)
			return parent;
		if(parent -> data > value)
			parent = parent -> left;
		if(parent -> data < value)	
			parent = parent -> right;	
	}
}

//prints tree inoder, preorder and post order
void BST::printTree() const
{
	cout << "INORDER: ";
	inorder(root);
	cout << endl << "PREORDER: ";
	preorder(root);
	cout << endl << "POSTORDER: ";
	postorder(root);
	cout << endl;
}

//prints tree inorder - LEFT -> NODE -> RIGHT
void BST::inorder(BNode * root) const
{
	if(root == NULL)
		return;
	
	inorder(root -> left);
	cout << root -> data << ",";
	inorder(root -> right);
}

//prints tree preorder - NODE -> LEFT -> RIGHT
void BST::preorder(BNode * root) const
{
	if(root == NULL)
		return;
	
	cout << root -> data << ",";
	preorder(root -> left);
	preorder(root -> right);
}

//prints tree postorder - LEFT -> RIGHT -> NODE
void BST::postorder(BNode * root) const
{
	if(root == NULL)
		return;
	
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << ",";
}
