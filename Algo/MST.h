#pragma once
#include <vector>
#include "Edge.h"
#include <iostream>
using namespace std;

class MST {
private:
	vector<Edge> listOfEdgesInTree;
	int weight = 0;
public:
	MST();
	~MST();
	int getWeight();
	void addEdge(Edge newEdge);
	bool isEdgeInMst(int u, int v);
	
};