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
		cout << "[���� ���� ����] �����ϴ� ���� �Է� " << endl;
		return;
	}

	/* ���ο� ũ���� ��������Ʈ�� ���� */
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

	dfs(0); //���� 0�� �������� Ž�� ����

	/* Ž�� ���� �� �����Ҵ� ���� �޸� ���� */
	delete[] visited;
}

/* workhouse*/
void LinkedGraph::dfs(const int v)
{

	int cnt = 1 ;

	for ( int i = 0 ; i < n ; ++i )
	{
		/* �湮���� �ʾҴٸ� ,*/
		if ( !visited[i])
		{
			visited[i] = true;
			stack[++top] = i;

			cout << "   ������ " << cnt++ << " - " << i << " ";

			while ( top > -1 )
			{
				int currVertax = stack[top];  /* top ���� �ϳ��� �����ͼ� ,*/
				
				/* ù ��ũ�� ���� */
				LinkedNode<int>* w = adjLists[currVertax].node->link;

				while (w)
				{
					/* ������ ������ �湮 */
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

			cout << "   ������ " << cnt++ << " - " << i << " "  ;

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
	cout << "�Էµ� �׷����� ��������Ʈ ǥ��" << endl;

	for (int i = 0 ; i < n ; i++)
	{
		cout << i << " -> ";

		LinkedNode<int> *next = adjLists[i].node->link;

		int count = 0;

		/* ��������Ʈ i ��°�� ������ ��� ��� */
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

	cout << "������" << endl << endl;

	cout << "3. ��������Ʈ + DFS" << endl;
	dfs();
	cout << endl;

	cout << "4. ��������Ʈ + BFS" << endl;
	bfs();

	cout << endl;
}