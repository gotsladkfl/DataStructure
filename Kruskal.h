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

	int collapsingFind(int v); // ���� v�� �����ϴ� ������ ��ȯ
	void weightedUnion(int v1, int v2); // �ΰ��� ���Ұ� ���� ������ ��ģ��

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

	cout << "������ ����ġ �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit): ";
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


	/* ���� , ���� , ����ġ�� �Է¹��� */
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
	
	//cout << "���� �б� ����" << endl;
}

void Kruskal::printCalMst()
{
	HeapNode e;
	int uSet, vSet, edgeCount = 0, sum = 0;

	while (edgeCount < vertaxCnt - 1) // ������ ������ n - 1 �� �� �� ����
	{
		e = minheap.deleteHeap(); // �ּ� ������ ����ġ�� �� ���� ��带 �����ͼ�
		// ���� ����ġ�� ���� ���� ������ ����
		uSet = collapsingFind(e.u);
		vSet = collapsingFind(e.v);

		if (uSet != vSet) // ������ ��ǥ ���Ұ� ���� ���� ��쿡��
		{
			sum += e.weight;
			edgeCount++; // ������ �ϳ� �ø���
			weightedUnion(uSet, vSet); // �� ������ ��ģ��


			/*  ������� ť�� ��� ���߿� ��¿����� ������ */
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
		cout << "���õ� ���� ";
		while (front != rear)
		{
			HeapNode tmpNode = queue[front];
			front = (front + 1) % QUEUE_SIZE;
			cout << "(" << tmpNode.v << " " << tmpNode.u << " " << tmpNode.weight << ")";
		}

		cout << endl;
		cout << "�ּҺ�� ����Ʈ���� ���� �� ����" << endl;
		cout << "�ּҺ���� ";

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
		cout << "[������� ���� ����] �ּҺ�� ����Ʈ���� ���� �� ���� " << endl;


	return;
}


/*  ���α׷� 5.26 �ر� ��Ģ for */
/* ���� v�� ���ϴ� ������ ��ȯ */

int Kruskal::collapsingFind(int v) 
{
	int i, temp;

	/* vertax v�� root�� ã�� */
	for (i = v; parent[i] >= 0; i = parent[i]);

	/* vertax v�� �����ϴ� ������ ��ǥ ���� */
	temp = i; 

	/* �ر� */
	/* ������ ��� ���ҵ��� �θ� i�� ���� */
	for (i = v; parent[i] >= 0; i = parent[i])
		parent[i] = temp; 

	return temp;
}


/*   ���α׷� 5.25 ���߱�Ģ�� �̿��� ������ ����    */
void Kruskal::weightedUnion(int v1, int v2) 
{
	if (num[v1] < num[v2]) 
	{
		/* �� �θ�� ���� */
		parent[v1] = v2; 
		num[v1] += num[v2];
	}
	else
	{
		parent[v2] = v1; 
		num[v2] += num[v1];
	}
}