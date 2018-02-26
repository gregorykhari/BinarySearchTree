//*************************************
//
// Author: Gregory Hinkson	
//
// Date: 7/12/2017
//
//**************************************

#include "DNode.h"
#include "DoublyLinkedList.h"

using namespace std;

//constructor for Doubly Linked List
DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
}

//destructor for Doubly Linked List to prevent memory leak
DoublyLinkedList::~DoublyLinkedList()
{
	//delete head node until list is empty
	while(!isEmpty())
	{
		deleteHead();
	}
}

//function inserts node at head of list
void DoublyLinkedList::insertNode(int data)
{
	DNode * new_node = new DNode;
	new_node -> data = data;	
	
	//if list is empty make new_node the head node
	if(isEmpty())
	{
		head = new_node;
		return;
	}

	new_node -> next = head;
	head -> prev = new_node;

	head = new_node;
}

//function inserts node with value data after node with value after
void DoublyLinkedList::insertNodeAfter(int data, int after)
{
	DNode * new_node = new DNode;
	new_node -> data = data;
	
	bool found = true;	
	
	//if list is empty make new_node the head node
	if(isEmpty())
	{
		head = new_node;
		return;
	}

	DNode * current = head;
	
	//traverse Doubly Linked List to find node containing value after
	while(current != NULL)
	{
		if(current -> data == after)
		{
			found = true;
			break;
		}
		
		current = current -> next;
	}	
	
		
	DNode * temp = current -> next;
	
	current -> next = new_node;
	new_node -> prev = current;

	//if new_node was inserted behind last node in list	
	if(temp == NULL)
		return;
	
	temp -> prev = new_node;
	new_node -> next = temp;
	
}

//function to delete node from Doubly Linked List containing value data
void DoublyLinkedList::deleteNode(int data)
{
	bool found = false;

	//if list is already empty
	if(isEmpty())
		return;

	DNode * current = head;	

	while(current != NULL)
	{
		if(current -> data == data){
			found = true;
			break;
		}
		
		current = current -> next;
	}	
	
	//if node does not exist in list	
	if(found == false)
		return;

	if(current == head)
		head = current -> next;

	current -> prev -> next = current -> next;
	current -> next -> prev = current -> prev;

	delete current;				
}

//function to delete head node from Doubly Linked List
void DoublyLinkedList::deleteHead()
{
	if(isEmpty())
		return;

	DNode *temp = head;
	
	head = head -> next;
	delete temp;	
}

//function returns a pointer to the first node in the Doubly Linked List
DNode & DoublyLinkedList::front()
{
	return *head;
}

//function returns true if Doubly Linked List contains nodes, false otherwise
bool DoublyLinkedList::isEmpty()
{
	return(head == NULL);
}

//function to print the data of the nodes in the Doubly Linked List
void DoublyLinkedList::printList()
{
	DNode * current = head;
	
	cout << "NULL";

	while(current != NULL)
	{
		cout << "<-->|  " << current -> data << "  |";
		current = current -> next;
	}
	cout << "<--> NULL" << endl;
}
