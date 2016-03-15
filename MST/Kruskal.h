#pragma once

#include "MinHeap.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define MAX_VERTEX 777
#define QUEUE_SIZE 777

class Kruskal
{

private:
	HeapNode queue[QUEUE_SIZE];
	int integerQueue[QUEUE_SIZE];
	int rear;
	int front;
	int iRear;
	int iFront;

	int parent[MAX_VERTEX];
	int num[MAX_VERTEX];
	int vertaxCnt;

	MinHeap minheap;

	int collapsingFind(int v); // 원소 v를 포함하는 집합을 반환
	void weightedUnion(int v1, int v2); // 두개의 원소가 속한 집합을 합친다

public:
	Kruskal()
	{
		vertaxCnt = rear = front = iRear = iFront = 0;

		for (int i = 0; i < MAX_VERTEX; i++)
		{
			parent[i] = -1;
			num[i] = 1;
		}
	}
	bool loadFile();
	void printCalMst();
};

bool Kruskal::loadFile()
{
	string quit = "quit";
	ifstream fin;
	string filename;
	int v , u , weight;

	cout << "무방향 가중치 그래프가 저장된 파일명을 입력하시오(종료는 quit): ";
	cin >> filename;
	
	if (filename == quit)
		return false;

	fin.open(filename);

	if (fin.fail())
	{
		cout << "do not exist filename.." << endl;
		exit(1);
	}
	
	fin >> vertaxCnt;
	//cout << vertaxCnt << endl;


	/* 정점 , 정점 , 가중치를 입력받음 */
	while ( !fin.eof() )
	{
		fin >> v;
		if (v == -1)
			break;
		fin >> u >> weight;
		minheap.insertHeap(v, u, weight);
		//cout << v << endl;
	}
	fin.close();

	return true;
	
	//cout << "파일 읽기 성공" << endl;
}

void Kruskal::printCalMst()
{
	HeapNode e;
	int uSet, vSet, edgeCount = 0, sum = 0;

	while (edgeCount < vertaxCnt - 1) // 간선의 갯수가 n - 1 이 될 때 까지
	{
		e = minheap.deleteHeap(); // 최소 힙에서 가중치가 젤 작은 노드를 가져와서
		// 가장 가중치가 가장 낮은 간선을 선택
		uSet = collapsingFind(e.u);
		vSet = collapsingFind(e.v);

		if (uSet != vSet) // 서로의 대표 원소가 같지 않은 경우에만
		{
			sum += e.weight;
			edgeCount++; // 간선을 하나 늘린다
			weightedUnion(uSet, vSet); // 두 집합을 합친다


			/*  결과물을 큐에 담고 나중에 출력용으로 쓰려고 */
			queue[rear] = e;
			rear = (rear + 1) % QUEUE_SIZE;
			integerQueue[iRear] = e.weight;
			iRear = (iRear + 1) % QUEUE_SIZE;
		}
		if (edgeCount == vertaxCnt - 1)
			break;
		if (minheap.getHeapSize() < 0)
			break;
	}
	if (edgeCount == vertaxCnt - 1)
	{
		cout << "선택된 간선 ";
		while (front != rear)
		{
			HeapNode tmpNode = queue[front];
			front = (front + 1) % QUEUE_SIZE;
			cout << "(" << tmpNode.v << " " << tmpNode.u << " " << tmpNode.weight << ")";
		}

		cout << endl;
		cout << "최소비용 신장트리를 구할 수 있음" << endl;
		cout << "최소비용은 ";

		while (true)
		{
			int tmp = integerQueue[iFront];
			iFront = (iFront + 1) % QUEUE_SIZE;
			cout << tmp;
			if (iFront != iRear)
				cout << "+";
			else
				break;
		}

		cout << " = " << sum << endl;
	}
	else
		cout << "[연결되지 않은 간선] 최소비용 신장트리를 구할 수 없음 " << endl;


	return;
}


/*  프로그램 5.26 붕괴 규칙 for */
/* 원소 v가 속하는 집합을 반환 */

int Kruskal::collapsingFind(int v) 
{
	int i, temp;

	/* vertax v의 root를 찾음 */
	for (i = v; parent[i] >= 0; i = parent[i]);

	/* vertax v를 포함하는 집합의 대표 원소 */
	temp = i; 

	/* 붕괴 */
	/* 집합의 모든 원소들의 부모를 i로 설정 */
	for (i = v; parent[i] >= 0; i = parent[i])
		parent[i] = temp; 

	return temp;
}


/*   프로그램 5.25 가중규칙을 이용한 합집합 변형    */
void Kruskal::weightedUnion(int v1, int v2) 
{
	if (num[v1] < num[v2]) 
	{
		/* 새 부모로 변경 */
		parent[v1] = v2; 
		num[v1] += num[v2];
	}
	else
	{
		parent[v2] = v1; 
		num[v2] += num[v1];
	}
}