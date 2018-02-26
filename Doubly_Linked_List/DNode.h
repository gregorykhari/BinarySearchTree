//*********************************
//
// Author: Gregory Hinkson	
//
// Date: 7/12/2017
//
//*********************************

#ifndef DNODE_H
#define DNODE_H

class DNode {
	friend class DoublyLinkedList;
private:
	int data;
	DNode *prev;
	DNode *next;
};

#endif

