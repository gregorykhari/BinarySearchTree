//**********************************
//
// Author: Gregory Hinkson
//
// Date: 19/1/2018
//
//**********************************

#include "ANode.h"
#include "AdjacencyList.h"
#include <iostream>
#include <typeinfo>

AdjacencyList::AdjacencyList()
{	
	int size;
	std::cout << "Enter the size of the adjacency list" << std::endl;
	std::cin >> size;
	
	//initialize adj_array to size of graph input
	adj_size = size;
	current_index = 0;

	adj_list.resize(adj_size);
	
	for(int i = 0; i < adj_size; i++)
	{
		adj_list[i] = NULL;
	}	
}

AdjacencyList::~AdjacencyList()
{

}

//function to insert node into next available position in adj_list
void AdjacencyList::insertNode(int value)
{
	//create new node to insert 
	ANode * new_node = new ANode;
	new_node -> value = value;
	new_node -> next = NULL;
	
	//insert new node into adj_list
	adj_list[current_index] = new_node;

	current_index++;
}

//function to delete node from adj_list
void AdjacencyList::deleteNode(int value)
{
	for(int i = 0; i < adj_size; i++)
	{
		if(adj_list[i] == NULL)
			continue;

		//delete node by setting it = to null
		if(adj_list[i] -> value == value)
		{	
			adj_list[i] = NULL;
		}

	}
}

//function to add edge between two nodes
void AdjacencyList::addEdge(int source, int destination)
{
	//check if both the source node and the destination node in adj_list
	if(!nodeExists(source) || !nodeExists(destination))
	{
		std::cout << "Node missing - cannot add edge" << std::endl;
		return;
	}

	//create new node and set equal to destination
	ANode * neighbour_node = new ANode;
	neighbour_node -> value = destination;
	neighbour_node -> next = NULL;
	
	//get index of source in adj_list
	int source_loc = nodeLocation(source);
	
	//ANode * cursor = adj_list[source_loc];
	
	if(adj_list[source_loc] -> next == NULL){
		adj_list[source_loc] -> next = neighbour_node;
	} else {
		ANode * temp = adj_list[source_loc] -> next;
		adj_list[source_loc] -> next = neighbour_node;
		neighbour_node -> next = temp;
		
	}
}

//function to delete edge between two nodes
void AdjacencyList::deleteEdge(int source, int destination)
{
	//get location of source node in adj_list
	int source_loc = nodeLocation(source);

	//precheck to see if nodes actually exist	
	if((source_loc == -1) || nodeLocation(destination) == -1)
		return;
	
	//set pointer to first neighbour node of source 
	ANode * precursor = adj_list[source];
	ANode * cursor = adj_list[source_loc] -> next;

	while(cursor != NULL)
	{
		//if node with value destination is found, delete node and set node before to point to node after	
		if(cursor -> value == destination){
			precursor = cursor -> next;
			delete cursor;
			return;
		}
		precursor = cursor;	
		cursor = cursor -> next;
	}

}

//function returns true if node exists with adj_list, false otherwise
bool AdjacencyList::nodeExists(int value)
{
	for(int i = 0; i < adj_size; i++)
	{
		if(adj_list[i] == NULL)
			continue;

		//return true if found
		if(adj_list[i] -> value == value)
			return true;
	}
	
	return false;
}

//function returns the index of the node with value
int AdjacencyList::nodeLocation(int value)
{
	for(int i = 0; i < adj_size; i++)
	{
		if(adj_list[i] == NULL)
			continue;

		if(adj_list[i] -> value == value)
			return i;
	}	
	return -1;
}

//function to print the adj_list
void AdjacencyList::printList()
{	
	std::cout << "---" << std::endl;
	
	//for each index in adj_list
	for(int i = 0; i < adj_size; i++)
	{

		//if no node in adj_list[i] skip
		if(adj_list[i] == NULL)
		{	
			std::cout << "\n" << std::endl;
			continue;
		}

		//print adj_list[i]
		std::cout << adj_list[i] -> value;

		//print neighbours of adj_list[i]
		ANode * cursor = adj_list[i] -> next;
		while(cursor != NULL)
		{
			std::cout << "-->" << cursor -> value;
			
			cursor = cursor -> next;
		}	
		std::cout << "\n---" << std::endl;
	}
	std::cout << "---" << std::endl;
}
