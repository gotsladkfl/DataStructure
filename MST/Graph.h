#pragma once

#include <iostream>

using namespace std;

class Graph
{
public :

	Graph(){	n = 0; e = 0;  };
	Graph(int n) { this->n = n; e = 0; };
	Graph(int n, int e){ this->n = n; this->e = e; };

	virtual ~Graph() {} // ���� �ı���
	
	bool IsEmpty() const { return n == 0;} // �׷����� ������ ������ true�� ��ȯ
	int numberOfVertices() const { return  n; } // �׷����� ������ ���� ��ȯ
	int numberOfEdges() const { return e; } // �׷����� ������ ���� ��ȯ

	virtual int degree( int u ) const  = 0; // ���� u�� ������ ������ ���� ��ȯ
	virtual bool existsEdge( int u, int v ) const = 0; // �׷����� ����(u,v) �� ������ true�� ��ȯ
	virtual void insertVertex( int v ) = 0; // ����v�� ���� ; v�� ������ ������ ����

	virtual void insertEdge( int u, int v ) = 0; // ���� (u,v)�� �׷����� ����
	virtual void deleteVertex(int v ) = 0;      // ���� v �� �̿� ������ ��� ������ ����
	virtual void deleteEdge( int u, int v ) = 0; // �׷����� ���� (u,v)�� ����
	virtual void printSearch() = 0;    // Ž�� ��� 

	/* driver */
	virtual void dfs() = 0;
	virtual void bfs() = 0;

	/* workhorse */
	virtual void dfs(const int v) = 0;
	virtual void bfs(const int v) = 0;
protected:
	int n; // ������ ��
	int e; // ������ ��
};
