#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	graph.clear();
}

void Graph::MakeEmptyGraph(int n)
{
	int i;
	for (i = 1; i <= n; i++) {
		List* newList = new List(i);
		graph.push_back(*newList);
	}
}

bool Graph::IsAdjacent(int u, int v)
{
	if (u <= 0 || u >= graph.size())
		return false;
	return graph.at(u-1).findEdge(v);
}

List Graph::GetAdjList(int u)
{
	//create exception message if 'u' doesn't exist
	return graph.at(u-1);
}

void Graph::AddEdge(int u, int v, int c)
{
	//create exception message if 'u' or 'v' doesn't exist
	graph.at(u-1).insertToEnd(v, c);
	graph.at(v-1).insertToEnd(u, c);
	Edge newEdge(u, v, c, nullptr, nullptr);
	listOfEdges.push_back(newEdge);
}

void Graph::RemoveEdge(int u, int v)
{
	graph.at(u-1).findEdgeAndRemoveIt(v);
	graph.at(v-1).findEdgeAndRemoveIt(u);
}

int Graph::getGraphSize()
{
	return graph.size();
}
