#include "DFS.h"

int white = 0;
int grey = 1;
int black = 2;

// DFS visit function
void Visit(vector<int>& Color,Graph& g, int u) {
	Color[u] = grey;
	Edge* curr = g.GetAdjList(u).getHead();
	while(curr != nullptr){
		int v = curr->getV();
		if (Color[v] == white)
			Visit(Color, g, v);

		curr = curr->getNext();
	}
	Color[u] = black;
}

// return true if the graph is connective, using DFS
bool isConnective(Graph& g)
{

	int n = g.getGraphSize();
	vector<int> Color;

	// adding dummy
	Color.push_back(-1);

	for (int i = 1; i <= n; i++) {
		Color.push_back(white);
	}

	Visit(Color, g, 1);

	for (int i = 1; i < n; i++) {
		if (Color[i] == white)
			return false;
	}

	return true;
}

