

#pragma once

#define HEAP_SIZE 777


class HeapNode
{
	friend class MinHeap;
	friend class Kruskal;
private:
	/*     정점1,2 그리고 가중치    */
	int v;
	int u;
	int weight;
};


class MinHeap
{
private:
	HeapNode mstHeap[HEAP_SIZE];
	int heapSize;
	/*   최소 힙에 노드를 추가  */
	void internal_insertHeap(HeapNode heapNode); 
public:
	MinHeap()
	{	
		for (int i = 0; i < HEAP_SIZE; i++)
			mstHeap[i] = HeapNode();
		heapSize = 0;
	}

	int getHeapSize()
	{
		return heapSize;
	}
	/*   삭제  */
	HeapNode deleteHeap();

	/* insert driver  */
	void insertHeap(int v, int u, int weight);
};



void MinHeap::internal_insertHeap(HeapNode heapNode)
{
	int currentNode = ++heapSize;
	
	/* 루트노드가 아니고 , 부모노드가 더 크다면 */
	while (currentNode != 1 && (heapNode.weight < mstHeap[currentNode / 2].weight))
	{
		/* 루트로 올라감 */
		mstHeap[currentNode] = mstHeap[currentNode / 2];  /* 부모 노드로 이동 ( 부모는 자식으로 내리고 ) */
		currentNode /= 2;
	}

	/*  부모로 달아줌  */
	mstHeap[currentNode] = heapNode;
}


/*   노드의 정보를 받아서 insert */
void MinHeap::insertHeap(int v, int u, int weight)
{
	HeapNode heapNode;
	heapNode.v = v;
	heapNode.u = u;
	heapNode.weight = weight;

	internal_insertHeap(heapNode);
}


HeapNode MinHeap::deleteHeap()
{

	/* child 는 currnetNode 의 자식  */
	int currentNode = 1, child = 2;
	HeapNode data, temp;

	data = mstHeap[currentNode];
	temp = mstHeap[heapSize--]; // 삭제에 의한 size 감소

	while (child <= heapSize)
	{
		//자식 노드간 작은 수 비교 
		if ((child < heapSize) && ( mstHeap[child].weight) > mstHeap[child + 1].weight)
			child++;

		/* currentNode에 lastE를 삽입할 수 있는 가? */
		if (temp.weight <= mstHeap[child].weight) 
			break;  //yes

		/* 자식으로 이동 */
		mstHeap[currentNode] = mstHeap[child];  
		currentNode = child;  child *= 2; // 한 레벨 내려감
	}

	mstHeap[currentNode] = temp;
	return data;
}

