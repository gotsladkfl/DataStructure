#include "MatrixGraph.h"

MatrixGraph::MatrixGraph() : Graph()
{
	matrix = NULL;
	front = rear = 0;
	top = -1;
}

MatrixGraph::MatrixGraph(int n) : Graph(n)
{
	front = rear = 0;
	top = -1;

	matrix = new int*[n];

	for ( int i = 0 ; i < n ; i++ )
	{
		matrix[i] = new int[n];
	}
}

MatrixGraph::~MatrixGraph() 
{
	for ( int i = 0 ; i < n ; i++ )
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}



void MatrixGraph::dfs()
{
	visited = new bool[n];

	for (int i = 0; i < n; i++)
		visited[i] = false;

	dfs(0); //���� 0�� �������� Ž�� ����

	/* Ž�� ���� �� �����Ҵ� ���� �޸� ���� */
	delete[] visited;
}


void MatrixGraph::dfs(const int v)
{
	int cnt = 1;

	for ( int i = 0 ; i < n ; i++ )
	{
		if ( !visited[i] ) // �湮 �������� ���� 
		{
			visited[i] = true;

			stack[++top] = i;

			cout << " ������" << cnt++ << " - " << i << " ";

			// cout << "ttt" << endl;
			while ( top > -1 )
			{
				int currVertax = stack[top];  /* top ���� �ϳ��� �����ͼ� ,*/

				for (int w = 0 ; w <= n ; w++ )
				{
					if (w == n) // ������ ������ �����ߴٸ� top ����.
					{
						top--;
						break;
					}

					if (matrix[currVertax][w] && !visited[w])  /* ���� ���� �ְ� , �湮�� ���� ���ٸ� */
					{
						visited[w] = true; // �湮 üũ �� 

						cout << w << " ";  // ���� ��� 
						stack[++top] = w;  // �̾ �� ������ ���ÿ� ����

						break;
					}
				}
			}

			cout << endl << endl;
		}
	}
}



void MatrixGraph::bfs()
{
	visited = new bool[n];

	for ( int i = 0 ; i < n ; i++ )
		visited[i] = false ;

	bfs(0);
	
	delete[] visited;
}

void MatrixGraph::bfs(const int v)
{
	int cnt = 1;

	for (int i = 0 ; i < n ; i++ )
	{
		if ( !visited[i] )
		{
			queue[rear] = i;
			rear = (rear + 1) % 10000;

			cout << "  ������" << cnt ++ << " - " << i << " ";

			visited[i] = true;

			while (front != rear )
			{
				/* ���� w�� ���� */

				int currVertax = queue[front];
				front = (front + 1) % 10000;

				/* �� ���� w�� ���� �� �� �ְ� , �� �� �ִ� ������ �湮���� ���� ���̸� "���" ť�� �߰� */
				for ( int w = 0 ; w < n ; w++ )
				{
					if (matrix[currVertax][w] && !visited[w])
					{
						visited[w] = true;

						cout << w << " ";

						queue[rear] = w;
						rear = (rear + 1) % 10000;
					}
				}
			}
			cout << endl;
		}
	}
}


////////////////////////////////////////////////////////////////


/*  ���� u�� ���� ������ ������ ���� ��ȯ�ϴ� �޼ҵ� */
int MatrixGraph::degree( int u )  const
{
	int cnt = 0 ;

	for ( int i = 0 ; i < n ; i++ )
		if ( matrix[u][i] == 1 )  
			cnt++;

	return cnt;
}


/*  �׷����� ���� u,v�� ������ true ��ȯ */
bool MatrixGraph::existsEdge( int u, int v )  const
{
	return matrix[u][v] == 1;
}


/*  ����v�� ���� ; v�� ������ ������ ����  */
/*  ũ�� ����  */
void MatrixGraph::insertVertex( int v )  
{
	if ( v < n )
	{
		cout << "[���� ���� ����] �����ϴ� ���� �Է� " << endl;
		return;
	}

	int **tmp = new int*[v];

	for ( int i = 0 ; i < v; i++ )
		tmp[i] = new int[v];

	for ( int i = 0 ; i < v; i++ )
		for ( int j = 0 ; j < v; j++ )
			tmp[i][j] = 0;

	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < n ; j++ )
			tmp[i][j] = matrix[i][j];

	matrix = tmp;

	n = v ;
}

void MatrixGraph::insertEdge( int u, int v )  
{
	if ( u > n || v > n )
	{
		cout << " [���� ���� ���� ] �������� �ʴ� ���� �Է� " << endl;
		return;
	}

	matrix[u][v] = 1;
	matrix[v][u] = 1;
	e++;
}

void MatrixGraph::deleteVertex(int v )  
{
	if ( v > n )
	{
		cout << "[���� ���� ����] �������� �ʴ� ���� �Է� " << endl ;
		return;
	}

	for ( int i = 0 ; i < n ; i++ )
	{

		if ( i == v )
			for ( int j = 0 ; j < n ; j++ )
				matrix[i][j] = 0;
		else
			matrix[i][v] = 0;
	}
}

void MatrixGraph::deleteEdge( int u, int v )  
{
	if ( u > n || v > n )
	{
		cout << "[���� ���� ����] �������� �ʴ� ���� �Է� " << endl;
		return;
	}

	matrix[u][v] = 0;
	e--;
}


////////////////////////////////////////////////////////////////





/*  ������Ŀ� ���� ǥ��, Ž�� 2���� ��� */
void MatrixGraph::printSearch()
{
	cout << "�Էµ� �׷����� ���� ��� ǥ��" << endl;

	for ( int i = 0 ; i < n ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
			cout << matrix[i][j] << " "; 

		cout << endl;
	}
	cout << endl;

	cout << "-----------------------------" << endl;
	cout << "������" << endl << endl;

	cout << "1. ������� + DFS" << endl ;
	dfs();
	cout << endl ;
	cout << "-----------------------------" << endl;


	cout << "2. ������� + BFS" << endl;
	bfs();

	cout << endl;
	cout << "-----------------------------" << endl;
}
