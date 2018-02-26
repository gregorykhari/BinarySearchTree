#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include"NodeHeader.h"

class LinkedList
{
public:
	LinkedList() :head(nullptr) {};
	~LinkedList();
	void insertNode(int);
	void deleteNode();
	void printList();
	bool isEmpty();
	Node & front();
	LinkedList & operator=(LinkedList* &);
private:
	Node* head;
};
#endif

