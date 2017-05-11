//*********************************************
//
// Author: Gregory Hinkson
//
// Date Modified: 5/10/2017
// 
//*********************************************

#ifndef BNODE_H
#define BNODE_H

#include<stdlib.h>

using namespace std;

struct BNode
{
	int data;
	BNode * left;
	BNode * right;
  BNode(int d) : data(d), left(NULL), right(NULL){};
};

class BST
{
public:
	BST();//constructor
	void insertLeaf(int);//inserts new node containing value
	bool isEmpty() const;//returns true if tree is empty
	bool search(int) const;//returns true if value in tree
	void deleteLeaf(int);//deletes node from tree containing value
	void printTree() const;//calls inorder, preorder and postorder
private:
	BNode * deleteAuxillary(BNode *, int) const;//returns pointer to node to be deleted
	BNode * getParent(int) const;//returns pointer to parent of value
	int getMinRight(BNode *) const;//returns min value in right subtree
 
  void inorder(BNode *) const;//prints tree inorder 
	void preorder(BNode *) const;//prints tree preorder
	void postorder(BNode *) const;//prints tree postorder
	BNode * root;
};

#endif
