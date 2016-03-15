



/*

              작성자 : 20111299 조재용
			작성일자 : 2015.9.29 ( 마지막 수정 10.11 18:52)
		

						2번   
						     사용한 자료구조(최소힙) 의 이유  :
						
						인접행렬이나 인접리스트의 경우 최소가중치를 찾는데 탐색시간이 좀 더 오래걸릴 것 같아서
						최소 힙을 사용하여 최소 가중치를 빅오(log n)의 시간만큼의 시간으로 결정하여 edge를 구성하였음.
						또 히프 자체를 구성하는데 걸리는 시간이 빅오(edge) 만큼 걸리지 않음.

						합집합 및 붕괴법칙 이해의 참고주소 : http://mgkim.egloos.com/1007300
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
		cout << "프로그램을 선택하세요 ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit]) : ";
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
			cout << "[프로그램 종료]" << endl;
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