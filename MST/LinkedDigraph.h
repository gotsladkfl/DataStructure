#pragma once
#include "Graph.h"
#include "LinkedList.h"
class LinkedDigraph : public Graph
{
protected :

	LinkedList<int> *adjLists;
	int* count ;

private :

	void topologicalSort() ;

public :

	LinkedDigraph() ;
	LinkedDigraph(int n) ;
	~LinkedDigraph() ;

	virtual int degree(int u) const { return 1; };
	virtual bool existsEdge(int u, int v) const{ return true; };
	virtual void insertVertex(int v);

	virtual void insertEdge(int u, int v);

	virtual void deleteVertex(int v){};
	virtual void deleteEdge(int u, int v){};


	/* driver */
	virtual void dfs(){};
	virtual void bfs(){};

	/* workhorse */
	virtual void dfs(const int v){};
	virtual void bfs(const int v){};
	virtual void printSearch() { printTopologicalSort(); };

	void printTopologicalSort();
};