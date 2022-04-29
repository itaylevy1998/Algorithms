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
	for (i = 0; i <= n; i++) {
		List* newList = new List(i);
		graph.push_back(*newList);
	}
}

bool Graph::IsAdjacent(int u, int v)
{
	//check if u is a valid vertex in graph
	if (u < 1 || u > graph.size())
		return false;
	return graph.at(u).findEdge(v);
}

List& Graph::GetAdjList(int u)
{
	//create exception message if 'u' doesn't exist
	return graph.at(u);
}

void Graph::AddEdge(int u, int v, int c)
{
	//create exception message if 'u' or 'v' doesn't exist
	graph.at(u).insertToEnd(u, v, c);
	graph.at(v).insertToEnd(v, u, c);
	Edge newEdge(u, v, c, nullptr, nullptr);
	listOfEdges.push_back(newEdge);
}

void Graph::RemoveEdge(int u, int v)
{
	if (u < 1 || u > getGraphSize()) {
		throw(1);
		/*cout << "Invalid Input!";
		exit(1);*/
	}
	
	graph.at(u).findEdgeAndRemoveIt(v);
	graph.at(v).findEdgeAndRemoveIt(u);
	deleteEdgeFromList(u, v);
}

int Graph::getGraphSize()
{
	return graph.size() - 1;
}

vector<Edge>& Graph::getListOfEdges()
{
	return listOfEdges;
}

int Graph::getNumOfEdges()
{
	return listOfEdges.size();
}

void Graph::deleteEdgeFromList(int u, int v)
{
	int i = 0;
	for (auto& element : listOfEdges) {
		if (element.getU() == u && element.getV() == v) {
			listOfEdges.erase(listOfEdges.begin() + i);
			return;
		}
		i++;
		
	}

}

void Graph::setSorted()
{
	isSorted = true;
}

bool Graph::getSorted()
{
	return isSorted;
}

