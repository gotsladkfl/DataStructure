#pragma once

#include <iostream>

using namespace std;

class Graph
{
public :

	Graph(){	n = 0; e = 0;  };
	Graph(int n) { this->n = n; e = 0; };
	Graph(int n, int e){ this->n = n; this->e = e; };

	virtual ~Graph() {} // 가상 파괴자
	
	bool IsEmpty() const { return n == 0;} // 그래프에 정점이 없으면 true를 반환
	int numberOfVertices() const { return  n; } // 그래프의 정점의 수를 반환
	int numberOfEdges() const { return e; } // 그래프의 간선의 수를 반환

	virtual int degree( int u ) const  = 0; // 정점 u에 인접한 간선의 수를 반환
	virtual bool existsEdge( int u, int v ) const = 0; // 그래프에 간선(u,v) 가 있으면 true를 반환
	virtual void insertVertex( int v ) = 0; // 정점v를 삽입 ; v는 인접한 간선이 없음

	virtual void insertEdge( int u, int v ) = 0; // 간선 (u,v)를 그래프에 삽입
	virtual void deleteVertex(int v ) = 0;      // 정점 v 와 이에 인접한 모든 간선을 삭제
	virtual void deleteEdge( int u, int v ) = 0; // 그래프에 간선 (u,v)를 삭제
	virtual void printSearch() = 0;    // 탐색 출력 

	/* driver */
	virtual void dfs() = 0;
	virtual void bfs() = 0;

	/* workhorse */
	virtual void dfs(const int v) = 0;
	virtual void bfs(const int v) = 0;
protected:
	int n; // 정점의 수
	int e; // 간선의 수
};
