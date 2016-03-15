

#pragma once

#define HEAP_SIZE 777


class HeapNode
{
	friend class MinHeap;
	friend class Kruskal;
private:
	/*     ����1,2 �׸��� ����ġ    */
	int v;
	int u;
	int weight;
};


class MinHeap
{
private:
	HeapNode mstHeap[HEAP_SIZE];
	int heapSize;
	/*   �ּ� ���� ��带 �߰�  */
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
	/*   ����  */
	HeapNode deleteHeap();

	/* insert driver  */
	void insertHeap(int v, int u, int weight);
};



void MinHeap::internal_insertHeap(HeapNode heapNode)
{
	int currentNode = ++heapSize;
	
	/* ��Ʈ��尡 �ƴϰ� , �θ��尡 �� ũ�ٸ� */
	while (currentNode != 1 && (heapNode.weight < mstHeap[currentNode / 2].weight))
	{
		/* ��Ʈ�� �ö� */
		mstHeap[currentNode] = mstHeap[currentNode / 2];  /* �θ� ���� �̵� ( �θ�� �ڽ����� ������ ) */
		currentNode /= 2;
	}

	/*  �θ�� �޾���  */
	mstHeap[currentNode] = heapNode;
}


/*   ����� ������ �޾Ƽ� insert */
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

	/* child �� currnetNode �� �ڽ�  */
	int currentNode = 1, child = 2;
	HeapNode data, temp;

	data = mstHeap[currentNode];
	temp = mstHeap[heapSize--]; // ������ ���� size ����

	while (child <= heapSize)
	{
		//�ڽ� ��尣 ���� �� �� 
		if ((child < heapSize) && ( mstHeap[child].weight) > mstHeap[child + 1].weight)
			child++;

		/* currentNode�� lastE�� ������ �� �ִ� ��? */
		if (temp.weight <= mstHeap[child].weight) 
			break;  //yes

		/* �ڽ����� �̵� */
		mstHeap[currentNode] = mstHeap[child];  
		currentNode = child;  child *= 2; // �� ���� ������
	}

	mstHeap[currentNode] = temp;
	return data;
}

