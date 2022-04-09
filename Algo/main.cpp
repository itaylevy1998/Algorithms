#include "Graph.h"
#include <vector>
#include <iostream>
using namespace std;

void main(int argc, char* argv[]){
	Graph newGraph;
	newGraph.MakeEmptyGraph(5);
	newGraph.AddEdge(1, 2, 10);
}