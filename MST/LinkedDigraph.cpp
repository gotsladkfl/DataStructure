#include "LinkedDigraph.h"

LinkedDigraph::LinkedDigraph() : Graph()
{
	adjLists = NULL ;
	count = 0 ;
}

LinkedDigraph::LinkedDigraph(int n) : Graph(n)
{
	adjLists = new LinkedList<int>[n];
	count = new int[n];
	for (int i = 0; i < n; i++)
		count[i] = 0;
}

LinkedDigraph::~LinkedDigraph() 
{
	for ( int i = 0 ; i < n ; i++ )
	{
		LinkedNode<int> *cur = adjLists[i].node;
		LinkedNode<int> *pre = 0;

		while (cur)
		{
			pre = cur;
			cur = cur->link ;

			delete pre ;
		}
	}

	delete [] adjLists ;
	delete [] count ;
}



void LinkedDigraph::insertVertex( int v ) 
{
	if ( v < n )
	{
		cout << "[���� ���� ����] �����ϴ� ���� �Է� " << endl;
		return;
	}

	/* ���ο� ũ���� ��������Ʈ�� ���� */
	LinkedList<int> *vt = new LinkedList<int>[v] ;

	for ( int i = 0 ; i < n ; i++ )
		vt[i] = adjLists[i];

	adjLists = vt;

	int *vtCnt = new int[v] ;
	
	for ( int i = 0 ; i < v ; i++ )
		vtCnt[i] = 0;

	for ( int i = 0 ; i < n ; i++ )
	    vtCnt[i] = count[i];


	count = vtCnt;

	n = v ;
}







void LinkedDigraph::insertEdge( int u, int v )
{
	/* ���� ����Ʈ�� ���� ������ �߰�  */
	adjLists[u].node->link = new LinkedNode<int>(v, adjLists[u].node->link);
	count[v]++;
}



/*   driver  */
void LinkedDigraph::printTopologicalSort()
{
	topologicalSort();
}


/*   workhouse  */
void LinkedDigraph::topologicalSort() // ��Ʈ��ũ�� n�� ������ ���� ������ �����Ѵ�.
{
	int top = -1 ;

	for ( int i = 0 ; i < n ; i++ ) // �����ڰ� ���� �������� ���� ��������
	{
		if ( count[i] == 0 )
		{
			count[i] = top ; // ����
			top = i ;
		}
	}

	cout << "������ �ϳ��� ���� ����  : " ;

	for ( int i = 0 ; i < n ; i++ )
	{
		if ( top == -1 )
		{
			cout << "Network has a cycle. " << endl ;
			return ;
		}

		int j = top ; top = count[top] ; // ������ ���ÿ��� ����

		cout << j << " " ;

		LinkedNode<int>* ji = adjLists[j].node->link; // == begin()

		while (ji) // j�� �ļ��� ���� ����
		{
			count[ji->data]--;

			if (count[ji->data] == 0){ count[ji->data] = top; top = ji->data; } //���ÿ� *ji�� ����

			ji = ji->link; // ���� ���� ++
		}
	}

	cout << endl ;
}
