



/*

              �ۼ��� : 20111299 �����
			�ۼ����� : 2015.9.29 ( ������ ���� 10.11 18:52)
		

						2��   
						     ����� �ڷᱸ��(�ּ���) �� ����  :
						
						��������̳� ��������Ʈ�� ��� �ּҰ���ġ�� ã�µ� Ž���ð��� �� �� �����ɸ� �� ���Ƽ�
						�ּ� ���� ����Ͽ� �ּ� ����ġ�� ���(log n)�� �ð���ŭ�� �ð����� �����Ͽ� edge�� �����Ͽ���.
						�� ���� ��ü�� �����ϴµ� �ɸ��� �ð��� ���(edge) ��ŭ �ɸ��� ����.

						������ �� �ر���Ģ ������ �����ּ� : http://mgkim.egloos.com/1007300
*/

#include <iostream>
#include "LinkedDigraph.h"
#include "LinkedGraph.h"
#include "Kruskal.h"
#include "FileHandler.h"
using namespace std;


int main()
{
	char input;
	FileHandler fih;

	Graph *mg = new MatrixGraph();
	Graph *lg = new LinkedGraph();
	Graph *ldg = new LinkedDigraph();
	Kruskal kruskal;


	while (1)
	{
		cout << "���α׷��� �����ϼ��� ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit]) : ";
		cin >> input;

		switch (input)
		{
		case 'S':  //dfs,bfs

			fih.readGraph(mg, lg);
			mg->printSearch();
			lg->printSearch();

			break;

		case 'M':  // kruscal 
			if (!kruskal.loadFile())
				break;
			kruskal.printCalMst();

			break;

		case 'T':  // topological
			fih.readGraph(ldg);
			ldg->printSearch();
			break;

		case 'Q':
			cout << "[���α׷� ����]" << endl;
			exit(1);
		default:
			break;

		}
	}

	delete mg;
	delete lg;
	delete ldg;

	return 0;
}