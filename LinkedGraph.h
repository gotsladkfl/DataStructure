#pragma once

#include "LinkedDigraph.h"

class LinkedGraph : public LinkedDigraph
{
private :
	/* stack  */
	int stack[10000];
	int top;
	bool *visited;

	/* queue */
	int queue[10000];
	int front;
	int rear;

	/* workhouse*/
	virtual void dfs(const int v);
	virtual void bfs(const int v);
public :

	LinkedGraph() ;
	LinkedGraph( int n ) ;
	~LinkedGraph() ;


	virtual int degree(int u) const { return 1; };
	virtual bool existsEdge(int u, int v) const{ return true; };
	virtual void insertVertex(int v);

	virtual void insertEdge(int u, int v);

	virtual void deleteVertex(int v){};
	virtual void deleteEdge(int u, int v){};

	/* driver */
	virtual void dfs();
	virtual void bfs();

	/* workhorse */
	virtual void printSearch();
};