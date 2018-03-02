//***********************************
//
// Author: Gregory Hinkson	
//
// Date: 1/19/2018
//
//***********************************

#include "ANode.h"
#include "AdjacencyList.h"
#include <iostream>

using namespace std;

void printMenu()
{
	cout << "\n\nEnter corresponding option to perform operation on Doubly Linked List" << endl;
	cout << "1. Insert Node Into Adjacency List" << endl;
	cout << "2. Delete Node From Adjacency List" << endl;
	cout << "3. Add Edge Between Two Nodes" << endl;
	cout << "4. Delete Edge From  Between Two Nodes" << endl;
	cout << "5. Print Adjacency List" << endl;
	cout << "6. Check if Node Exists" << endl;
	cout << "7. Check If Node B Is A Neighbour Of Node" << endl;
	cout << "OPTION: ";
}

int main()
{
	int option;
	int value;
	int src, dest; //source and destination of edges
	
	AdjacencyList adj;
	
	printMenu();
	cin >> option;

	while(option != 8)
	{
		cout << "\n" << endl;
		switch(option)
		{
			case 1:
				cout << "Enter value of node to add to list" << endl;
				cin >> value;
				adj.insertNode(value);
				break;
			case 2:
				cout << "Enter value of node to delete from list" << endl;
				cin >> value;
				adj.deleteNode(value);
				break;
			case 3:
				cout << "Enter source of edge" << endl;
				cin >> src;
				cout << "Enter destination of edge" << endl;
				cin >> dest;
				adj.addEdge(src,dest);
				break;
			case 4:
				cout << "Enter source of edge" << endl;
				cin >> src;
				cout << "Enter destination of edge" << endl;
				cin >> dest;
				adj.deleteEdge(src,dest);
				break;
			case 5:
				adj.printList();
				break;
			
			case 6:
				cout << "Enter value of node to check if exist" << endl;
				cin >> value;
				if(adj.nodeExists(value))
					cout << "Node with value " << value << " exists" << endl;
				else 
					cout << "Node with value " << value << " does not exists" << endl;
				break;
			/*	
			case 7:
				cout << "Enter source of edge" << endl;
				cin >> src;
				cout << "Enter destination of edge" << endl;
				cin >> dest;
				if(adj.isNeighbour(src,dest))
					cout << "Node with value " << src << " is a neighbour of node with value " << dest << endl;
				else 
					cout << "Node with value " << src << " is a not a neighbour of node with value " << dest << endl;
				break;
			default:
				cout << "Invalid option entered" << endl;
				break;
		*/
		}
		
		printMenu();
		cin >> option;
	}
}
