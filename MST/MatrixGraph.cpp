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

	dfs(0); //정점 0을 시작으로 탐색 시작

	/* 탐색 종료 후 동적할당 변수 메모리 해제 */
	delete[] visited;
}


void MatrixGraph::dfs(const int v)
{
	int cnt = 1;

	for ( int i = 0 ; i < n ; i++ )
	{
		if ( !visited[i] ) // 방문 안했으면 시작 
		{
			visited[i] = true;

			stack[++top] = i;

			cout << " 연결요소" << cnt++ << " - " << i << " ";

			// cout << "ttt" << endl;
			while ( top > -1 )
			{
				int currVertax = stack[top];  /* top 에서 하나를 꺼내와서 ,*/

				for (int w = 0 ; w <= n ; w++ )
				{
					if (w == n) // 마지막 정점에 도달했다면 top 감소.
					{
						top--;
						break;
					}

					if (matrix[currVertax][w] && !visited[w])  /* 가는 길이 있고 , 방문한 적이 없다면 */
					{
						visited[w] = true; // 방문 체크 후 

						cout << w << " ";  // 정점 출력 
						stack[++top] = w;  // 이어서 그 정점을 스택에 쌓음

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

			cout << "  연결요소" << cnt ++ << " - " << i << " ";

			visited[i] = true;

			while (front != rear )
			{
				/* 정점 w를 선택 */

				int currVertax = queue[front];
				front = (front + 1) % 10000;

				/* 그 정점 w로 부터 갈 수 있고 , 갈 수 있는 정점이 방문하지 않은 곳이면 "모두" 큐에 추가 */
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


/*  정점 u에 대해 인접한 간선의 수를 반환하는 메소드 */
int MatrixGraph::degree( int u )  const
{
	int cnt = 0 ;

	for ( int i = 0 ; i < n ; i++ )
		if ( matrix[u][i] == 1 )  
			cnt++;

	return cnt;
}


/*  그래프에 간선 u,v가 있으면 true 반환 */
bool MatrixGraph::existsEdge( int u, int v )  const
{
	return matrix[u][v] == 1;
}


/*  정점v를 삽입 ; v는 인접한 간선이 없음  */
/*  크기 변경  */
void MatrixGraph::insertVertex( int v )  
{
	if ( v < n )
	{
		cout << "[정점 생성 오류] 존재하는 정점 입력 " << endl;
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
		cout << " [간선 생성 오류 ] 존재하지 않는 정점 입력 " << endl;
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
		cout << "[정점 삭제 오류] 존재하지 않는 정점 입력 " << endl ;
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
		cout << "[간선 삭제 오류] 존재하지 않는 정점 입력 " << endl;
		return;
	}

	matrix[u][v] = 0;
	e--;
}


////////////////////////////////////////////////////////////////





/*  인접행렬에 대한 표현, 탐색 2가지 출력 */
void MatrixGraph::printSearch()
{
	cout << "입력된 그래프의 인접 행렬 표현" << endl;

	for ( int i = 0 ; i < n ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
			cout << matrix[i][j] << " "; 

		cout << endl;
	}
	cout << endl;

	cout << "-----------------------------" << endl;
	cout << "연결요소" << endl << endl;

	cout << "1. 인접행렬 + DFS" << endl ;
	dfs();
	cout << endl ;
	cout << "-----------------------------" << endl;


	cout << "2. 인접행렬 + BFS" << endl;
	bfs();

	cout << endl;
	cout << "-----------------------------" << endl;
}
