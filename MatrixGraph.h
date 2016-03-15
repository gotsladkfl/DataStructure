#pragma once

#include "Graph.h"

/* 

     ���� ����� ������ ������ �׷��� 
	 �߻�Ŭ���� Graph�� ��ӹ޾� �� �޼ҵ带 ������ 
*/


class MatrixGraph : public Graph
{
private :
	int **matrix ; // ������� ǥ����

	/* stack  */
	int stack[10000]; 
	int top ;
	bool *visited;

	/* queue */
	int queue[10000];
	int front;
	int rear;

	/* workhorse */
	virtual void dfs(const int v);
	virtual void bfs(const int v);
	

public :

	MatrixGraph() ;
	MatrixGraph( int n ) ;
	~MatrixGraph() ;

	virtual int degree( int u ) const  ;
	virtual bool existsEdge( int u, int v ) const ;
	virtual void insertVertex( int v )  ;

	virtual void insertEdge( int u, int v )  ;
	virtual void deleteVertex(int v )  ;
	virtual void deleteEdge( int u, int v )  ;

	/*  driver  */
	virtual void dfs();
	virtual void bfs();

	virtual void printSearch() ;

};