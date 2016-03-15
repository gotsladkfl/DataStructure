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
		cout << "[정점 생성 오류] 존재하는 정점 입력 " << endl;
		return;
	}

	/* 새로운 크기의 인접리스트를 생성 */
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
	/* 인접 리스트에 연결 정보를 추가  */
	adjLists[u].node->link = new LinkedNode<int>(v, adjLists[u].node->link);
	count[v]++;
}



/*   driver  */
void LinkedDigraph::printTopologicalSort()
{
	topologicalSort();
}


/*   workhouse  */
void LinkedDigraph::topologicalSort() // 네트워크의 n개 정점을 위상 순서로 나열한다.
{
	int top = -1 ;

	for ( int i = 0 ; i < n ; i++ ) // 선행자가 없는 정점들을 연결 스택으로
	{
		if ( count[i] == 0 )
		{
			count[i] = top ; // 생성
			top = i ;
		}
	}

	cout << "가능한 하나의 위상 정렬  : " ;

	for ( int i = 0 ; i < n ; i++ )
	{
		if ( top == -1 )
		{
			cout << "Network has a cycle. " << endl ;
			return ;
		}

		int j = top ; top = count[top] ; // 정점을 스택에서 꺼냄

		cout << j << " " ;

		LinkedNode<int>* ji = adjLists[j].node->link; // == begin()

		while (ji) // j의 후속자 수를 감소
		{
			count[ji->data]--;

			if (count[ji->data] == 0){ count[ji->data] = top; top = ji->data; } //스택에 *ji를 삽입

			ji = ji->link; // 다음 노드로 ++
		}
	}

	cout << endl ;
}
