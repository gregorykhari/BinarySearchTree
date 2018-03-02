//******************************************
//
// Author: Gregory Hinkson
//
// Date Modified: 5/8/2017
//
//******************************************

#ifndef GRPH
#define GRPH

#include <iostream>
#include <vector>

using namespace std;

struct vnode {
	int vertex; 
	vnode *next;
	vnode(int u, vnode *n): vertex(u), next(n){};
};
 
typedef vnode * vnodeptr;

class graph 
{
public:
	graph(); // interactive constructor using cin
	void bfs();
private:
	int size;
	vector<vnodeptr> adjList;
};

#endif
