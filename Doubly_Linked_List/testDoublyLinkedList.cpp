//**********************************
//
// Author: Gregory Hinkson
//
// Date: 7/12/2017
//
//**********************************

#include "DNode.h"
#include "DoublyLinkedList.h"

using namespace std;

void printMenu()
{
	cout << "Enter corresponding option to perform operation on Doubly Linked List" << endl;
	cout << "1. Insert Node Into DLL" << endl;
	cout << "2. Insert Node Into DLL After Node Containing Value" << endl;
	cout << "3. Delete Head Node From DLL" << endl;
	cout << "4. Delete Node From DLL Containing Value" << endl;
	cout << "5. Check if DLL is empty " << endl;
	cout << "6. Print DLL" << endl;
	cout << "8. Exit" << endl;
	cout << "OPTION: ";
}

int main()
{
	DoublyLinkedList dl;
	
	int data;
	int after;
	int option;
	
	printMenu();
	cin >> option;

	while(option !=  8)
	{
		switch(option)
		{
			case 1: 
				cout << "Enter data to add to new node" << endl;
				cin >> data;
				dl.insertNode(data);
				break;
			case 2:
				cout << "Enter data to add to new node" << endl;
				cin >> data;
				cout << "Enter data of node to add new node after" << endl;
				cin >> after;
				dl.insertNodeAfter(data,after);	
				break;
			case 3:
				dl.deleteHead();	
				break;
			case 4:
				cout << "Enter data of node to delete" << endl;
				cin >> data;	
				dl.deleteNode(data);
				break;
			case 5: 
				if(dl.isEmpty())
					cout << "DLL has no node" << endl;
				else 
					cout << "DLL has nodes" << endl;
				break;
			case 6:
				dl.printList();
				break;
			default:
				cout << "Invalid Option" << endl;

		}
		cout << "\n\n" << endl;	
		printMenu();
		cin >> option;

	}

	return 0;
}
