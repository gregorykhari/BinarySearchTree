//******************************************
//
// Author: Gregory Hinkson
//
// Date Modified: 5/8/2017
//
//******************************************

#include "graph.h"
#include <cassert>
#include <queue>
#include <iostream>

using namespace std;

graph::graph()
{
	int vertex;
	cout << "Enter the size of the Adjacency List" << endl;	
	cin >> size;
	adjList.resize(size,NULL);
  
	for(int i = 0; i < size; ++i) 
    	{
    		cout << "Enter neighbors of vertex " << i << " (Terminate by -1): " << endl;
		cin >> vertex;
    	
		while(vertex != -1) 
	    	{
  			adjList[i] = new vnode(vertex,adjList[i]); // insert at begining
    			cout << "Enter neighbor of vertex " << i << " (Terminate by -1)" << endl;
		    	cin >> vertex;
  	  	}
    	}
}


void graph::bfs()
{
	int start = 0;
	int current = start;
	int nbr;
	vnodeptr cursor;
	queue<int> Q;
	vector<bool> visited(size,false);
  	visited[start] = true;
  	Q.push(start);

  	while(!Q.empty())
  	{
    		current = Q.front();
   		cursor = adjList[current];
    
    		cout << current << " " ;
    
		while(cursor != NULL)
    		{
      
			nbr = cursor -> vertex;
      
			if(visited[nbr] == false)
      			{
        			Q.push(nbr);
        			visited[nbr] = true;
      			}
      		
		cursor = cursor -> next;
    		}
	Q.pop();
  	}
  
	cout << endl;
}

int main()
{
  	graph Alist;
  	Alist.bfs();

	return 0;
}
