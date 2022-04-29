#include "MST.h"

// constructor
MST::MST()
{
	weight = 0;
}

// destructor
MST::~MST()
{
	listOfEdgesInTree.clear();
}

// get the wight of the MST
int MST::getWeight()
{
	return weight;
}

// add new edge to the MST and update it's weight accordingly
void MST::addEdge(Edge newEdge)
{
	listOfEdgesInTree.push_back(newEdge);
	weight += newEdge.getWeight();
}

// return true if the given edge is part of the MST
bool MST::isEdgeInMst(int u, int v)
{
	for (auto& element : listOfEdgesInTree) {
		if (element.getU() == u && element.getV() == v) {
			return true;
		}
	}
	return false;
}
