#include "FileHandler.h"


/* 1번 문제에 대한 그래프 ( 인접 행렬, 리스트 ) */
void FileHandler::readGraph(Graph *graph1, Graph *graph2)
{
	string fileName;
	ifstream in;

	while (true)
	{
		cout << "그래프가 저장된 파일명을 입력하시오(종료는 quit) : ";

		cin >> fileName;

		if (fileName == "quit")
			break;

		in.open(fileName);

		if (in.fail())
		{
			cout << " [파일 읽기 오류] 다시 입력하세요. " << endl;
			continue;
		}

		int n;
		in >> n;

		graph1->insertVertex(n);
		graph2->insertVertex(n);

		int u, v;

		while ( !in.eof() )
		{

			in >> u;

			if (u == -1)
				break;

			in >> v;

			/*  간선에 추가 */
			graph1->insertEdge(u, v);
			graph2->insertEdge(u, v);
		}

		break;
	}
	in.close();
}

/* 3번 방향 그래프 */
void FileHandler::readGraph(Graph* graph)
{
	string fileName ;
	ifstream in ;

	while(true)
	{
		cout << "그래프가 저장된 파일명을 입력하시오(종료는 quit) : " ; 

		cin >> fileName ;

		if ( fileName =="quit") 
			break;

		in.open( fileName ) ;

		if (in.fail())
		{
			cout << " [파일 읽기 오류] 다시 입력하세요. " << endl;
			continue;
		}

		int n;
		in >> n;

		graph->insertVertex(n);

		int u , v;

		while ( !in.eof() )
		{
			
			in >> u;

			if ( u == -1 )
				break;

			in >> v;

			
			graph->insertEdge(u,v);
		}
		
		break;
	}
	in.close() ;
}

