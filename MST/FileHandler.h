#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "MatrixGraph.h"

using namespace std;

class FileHandler
{
public :
	void readGraph( Graph* graph) ;
	void readGraph( Graph* graph1, Graph* graph2) ;
};
