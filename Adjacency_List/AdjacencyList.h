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
	void insertNode(int);//insert node into adj_list
	void deleteNode(int);//delete node from adj_list
	void addEdge(int,int);//add Edge between two Nodes
	void deleteEdge(int,int);//delete Edge between two Nodes
	bool isEmpty();//return true if adjacency list is empty, false otherwise
	bool nodeExists(int);//returns true if node with value exists in adj_list
	bool isNeighbour(int,int);//return true if source is a neighbour of destination, false otherwise
	void printList();//print Adjacency List
private:
	void updateNextPosition();//helper function to update next_pos
	int nodeLocation(int);//helper function to return the 
	std::vector<ANode *> adj_list;
	int adj_size;//size of adj_list
	int next_pos;//next available position to insert node into adj_list
};

#endif
