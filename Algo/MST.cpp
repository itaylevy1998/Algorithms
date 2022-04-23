#include "MST.h"

MST::MST()
{
	weight = 0;
}

MST::~MST()
{
	listOfEdgesInTree.clear();
}

int MST::getWeight()
{
	return weight;
}


void MST::addEdge(Edge newEdge)
{
	listOfEdgesInTree.push_back(newEdge);
	weight += newEdge.getWeight();
}
