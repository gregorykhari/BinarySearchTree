//**********************************
//
// Author: Gregory Hinkson
//
// Date: 1/19/2018
//
//**********************************

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "ANode.h"
#include <vector>

class AdjacencyList
{	
public:
	AdjacencyList();
	~AdjacencyList();
	void insertNode(int);
	void deleteNode(int);
	void addEdge(int,int);//add Edge between two Nodes
	void deleteEdge(int,int);//delete Edge between two Nodes
	bool isEmpty();//return true if adjacency list is empty, false otherwise
	bool nodeExists(int);
	bool isNeighbour(int,int);//return true if source is a neighbour of destination, false otherwise
	void printList();//print Adjacency List
private:
	int nodeLocation(int);
	std::vector<ANode *> adj_list;
	int adj_size;
	int current_index;		
};

#endif
