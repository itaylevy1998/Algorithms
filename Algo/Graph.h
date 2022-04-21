#include "List.h"
#include <vector>
using namespace std;

class Graph {
private:
	vector<List> graph;
	vector<Edge> listOfEdges;
public:
	Graph();
	~Graph();
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	List GetAdjList(int u);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
	int getGraphSize();
	vector<Edge>& getListOfEdges();
	int getNumOfEdges();
};