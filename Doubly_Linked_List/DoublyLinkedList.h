//****************************************
//
// Author: Gregory Hinkson	
//
// Date: 7/12/2017
//
//****************************************

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

class DoublyLinkedList
{

public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void insertNode(int);
	void insertNodeAfter(int,int);//function inserts node with value data into list after node with value after
	void deleteHead();//function deletes value at head of the doubly linked list
	void deleteNode(int);//function to delete node containing specific data value
	DNode & front();
	void printList();
	bool isEmpty();
private:
	DNode * head;
};

#endif
