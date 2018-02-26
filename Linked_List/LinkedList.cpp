#include"LinkedList.h"
#include<iostream>

using namespace std;

LinkedList::~LinkedList()
{
	while (!isEmpty())
	{
		deleteNode();
	}
}

void LinkedList::insertNode(int data)
{
	Node *new_node = new Node;
	new_node->element = data;

	Node *temp = head;

	head = new_node;
	new_node->next = temp;
}

void LinkedList::deleteNode()
{
	Node *temp = head;
	head = head->next;
	delete temp;

}

LinkedList & LinkedList::operator=(LinkedList* &rhs)
{
	Node* temp_node = new Node;
	Node* rhs_current = rhs->head;

	while (rhs_current != nullptr)
	{
		temp_node->element = rhs_current->element;
		temp_node->next = rhs_current->next;
		rhs_current = rhs_current->next;
	}

	head = temp_node;
	temp_node = nullptr;

	return *this;
}

Node & LinkedList::front()
{
	return *head;
}

bool LinkedList::isEmpty()
{
	return (head == nullptr);
}

void LinkedList::printList()
{
	Node* current = head;
	cout << "NULL ";
	while (current != nullptr) {
		cout << " <--|" << current->element << "|" << current->next << "|";
		current = current->next;
	}
	cout << endl;
}