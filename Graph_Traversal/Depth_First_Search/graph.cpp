//******************************************
//
// Author: Gregory Hinkson
//
// Date Modified: 5/8/2017
//
//******************************************

#include "graph.h"
#include <cassert>
#include <stack>

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


void graph::dfs()
{
  	int start = 0;
  	int nbr;
	int current = start;
  
	stack<int> S;//keeps track of neighbours
	vector<bool> visited(size,false);//keeps track of nodes visited
  	vnodeptr cursor;
  	visited[start] = true;
	
	S.push(start);
     
	while (!S.empty())
	{
		current = S.top();
		cursor = adjList[current];
        
		cout << current << " " ;
		  
      		while (cursor != NULL)
		{
			nbr = cursor->vertex;
			  
			if (visited[nbr] == false)
			{
		      		visited[nbr] = true;
				S.push(nbr);
				break;
			}else {
				cursor = cursor->next;
			}
		}
		
		if (cursor == NULL)
			S.pop();
	}
   
	cout << endl;
}

int main()
{

	graph Alist;

	Alist.dfs();

	return 0;
}



   
  
