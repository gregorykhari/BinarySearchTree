#ifndef NODEHEADER_H
#define NODEHEADER_H

class Node
{
	friend class LinkedList;
private:
	int element;
	Node* next;
};
#endif
