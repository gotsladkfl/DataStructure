#include "FileHandler.h"


/* 1�� ������ ���� �׷��� ( ���� ���, ����Ʈ ) */
void FileHandler::readGraph(Graph *graph1, Graph *graph2)
{
	string fileName;
	ifstream in;

	while (true)
	{
		cout << "�׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit) : ";

		cin >> fileName;

		if (fileName == "quit")
			break;

		in.open(fileName);

		if (in.fail())
		{
			cout << " [���� �б� ����] �ٽ� �Է��ϼ���. " << endl;
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

			/*  ������ �߰� */
			graph1->insertEdge(u, v);
			graph2->insertEdge(u, v);
		}

		break;
	}
	in.close();
}

/* 3�� ���� �׷��� */
void FileHandler::readGraph(Graph* graph)
{
	string fileName ;
	ifstream in ;

	while(true)
	{
		cout << "�׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit) : " ; 

		cin >> fileName ;

		if ( fileName =="quit") 
			break;

		in.open( fileName ) ;

		if (in.fail())
		{
			cout << " [���� �б� ����] �ٽ� �Է��ϼ���. " << endl;
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

