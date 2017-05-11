//*********************************************
//
// Author: Gregory Hinkson
//
// Date Modified: 5/10/2017
// 
//*********************************************

#include"BNode.h"
#include<iostream>

using namespace std;

int main()
{

  BST tree;
  
  cout << "Inserting values : 19,13,27,6,16,21,35,14 into tree" << endl;
  tree.insertLeaf(19);
  tree.insertLeaf(13);
  tree.insertLeaf(27);
  tree.insertLeaf(6);
  tree.insertLeaf(16);
  tree.insertLeaf(21);
  tree.insertLeaf(35);
  tree.insertLeaf(14);
  tree.printTree();

  cout << endl;
  cout << "Is 13 in the tree? " << endl;
  cout << tree.search(13) << endl;
  cout << endl;
  
  cout << endl;
  cout << "Is 42 in the tree? " << endl;
  cout << tree.search(42) << endl;

  cout << endl;
  cout << "Deleting 19 from tree..." << endl;
  tree.deleteLeaf(19);
  
  cout << endl;
  cout << "Tree after 19 was deleted... " << endl;
  tree.printTree();
  
return 0;
}