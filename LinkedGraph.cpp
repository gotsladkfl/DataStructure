#include "LinkedGraph.h"

LinkedGraph::LinkedGraph() : LinkedDigraph() {
	rear = front = 0;
top = -1;
}

LinkedGraph::LinkedGraph(int n) : LinkedDigraph(n) { rear = front = 0;
top = -1;
}

LinkedGraph::~LinkedGraph() {}

void LinkedGraph::insertEdge( int u, int v )
{
	adjLists[u].node->link = new LinkedNode<int>(v, adjLists[u].node->link);
	adjLists[v].node->link = new LinkedNode<int>(u, adjLists[v].node->link);
}
void LinkedGraph::insertVertex(int v)
{
	if (v < n)
	{
		cout << "[정점 생성 오류] 존재하는 정점 입력 " << endl;
		return;
	}

	/* 새로운 크기의 인접리스트를 생성 */
	LinkedList<int> *vt = new LinkedList<int>[v];

	for (int i = 0; i < n; i++)
		vt[i] = adjLists[i];

	adjLists = vt;

	int *vtCnt = new int[v];

	for (int i = 0; i < v; i++)
		vtCnt[i] = 0;

	for (int i = 0; i < n; i++)
		vtCnt[i] = count[i];


	count = vtCnt;

	n = v;
}
/* driver */
void LinkedGraph::dfs()
{
	visited = new bool[n];

	for (int i = 0; i < n; i++)
		visited[i] = false;

	dfs(0); //정점 0을 시작으로 탐색 시작

	/* 탐색 종료 후 동적할당 변수 메모리 해제 */
	delete[] visited;
}

/* workhouse*/
void LinkedGraph::dfs(const int v)
{

	int cnt = 1 ;

	for ( int i = 0 ; i < n ; ++i )
	{
		/* 방문하지 않았다면 ,*/
		if ( !visited[i])
		{
			visited[i] = true;
			stack[++top] = i;

			cout << "   연결요소 " << cnt++ << " - " << i << " ";

			while ( top > -1 )
			{
				int currVertax = stack[top];  /* top 에서 하나를 꺼내와서 ,*/
				
				/* 첫 링크로 부터 */
				LinkedNode<int>* w = adjLists[currVertax].node->link;

				while (w)
				{
					/* 인접한 노드들을 방문 */
					if ( !visited[ w->data ] )
					{
						visited[ w->data ] = true ;

						cout << w->data << " " ;

						stack[++top] = w->data ;

						break ;
					}

					w = w->link ;
				}

				if (!w)
					top--;
			}
			cout << endl ;
		}
	}
}	


void LinkedGraph::bfs()
{
	visited = new bool[n];
	for (int i = 0 ; i < n ; i++)
		visited[i] = false;

	bfs(0);

	delete[] visited;
}
/* workhouse*/
void LinkedGraph::bfs(const int v)
{
	int cnt = 1 ;

	for ( int i = 0 ; i < n ; i++ )
	{
		if ( visited[i] == 0 )
		{
			queue[rear] = i;
			rear = (rear + 1) % 10000;

			cout << "   연결요소 " << cnt++ << " - " << i << " "  ;

			visited[i] = true ;

			while ( front != rear ) 
			{
				int currVertax = queue[front];
				front = (front + 1) % 10000;
				
				LinkedNode<int>* w = adjLists[currVertax].node->link;

				while ( w )
				{
					if ( !visited[ w->data ] )
					{
						visited[ w->data ] = true ;

						cout << w->data << " " ;

						queue[rear] = w->data;
						rear = (rear + 1) % 10000;
					}

					w = w->link ;
				}
			}
			cout << endl ;
		}
	}
}





void LinkedGraph::printSearch()
{
	cout << "입력된 그래프의 인접리스트 표현" << endl;

	for (int i = 0 ; i < n ; i++)
	{
		cout << i << " -> ";

		LinkedNode<int> *next = adjLists[i].node->link;

		int count = 0;

		/* 인접리스트 i 번째의 연결요소 모두 출력 */
		while (next)
		{
			if ( !count )
				cout << next->data;
			else
				cout << " - " << next->data;

			count++;
			next = next->link;
		}

		if ( !count )
			cout << "null";

		cout << endl;

	}
	cout << endl;

	cout << "연결요소" << endl << endl;

	cout << "3. 인접리스트 + DFS" << endl;
	dfs();
	cout << endl;

	cout << "4. 인접리스트 + BFS" << endl;
	bfs();

	cout << endl;
}