#include "Graph.h"

//constructor
Graph::Graph()
{
}

//destructor
Graph::~Graph()
{
	graph.clear();
}

// creates an dempty graph of size n.
void Graph::MakeEmptyGraph(int n)
{
	int i;
	for (i = 0; i <= n; i++) {
		List* newList = new List(i);
		graph.push_back(*newList);
	}
}

//gets two vertex u and v, and returns true if there is an edge between them.
bool Graph::IsAdjacent(int u, int v)
{
	//check if u is a valid vertex in graph
	if (u < 1 || u > graph.size())
		return false;
	return graph.at(u).findEdge(v);
}

// returns the adj list of a given vertex.
List& Graph::GetAdjList(int u)
{
	
	return graph.at(u);
}

//adding an edge to the graph.
void Graph::AddEdge(int u, int v, int c)
{
	graph.at(u).insertToEnd(u, v, c);
	graph.at(v).insertToEnd(v, u, c);
	Edge newEdge(u, v, c, nullptr, nullptr);
	listOfEdges.push_back(newEdge);
}

//removing a given edge from the graph.
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

//returns the size of the graph.
int Graph::getGraphSize()
{
	return graph.size() - 1;
}

//returns the vector of edges.
vector<Edge>& Graph::getListOfEdges()
{
	return listOfEdges;
}

//returns the num of edges in the graph/
int Graph::getNumOfEdges()
{
	return listOfEdges.size();
}

//deletes a given edge from the graph.
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

// calling this function means that the list of edges has already been sorted.
void Graph::setSorted()
{
	isSorted = true;
}

//returns the true if the list of edges is sorted.
bool Graph::getSorted()
{
	return isSorted;
}

