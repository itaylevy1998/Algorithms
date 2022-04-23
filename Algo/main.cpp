#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DisjointSets.h"
#include "MST.h"
#include "PriorityQueue.h"
#include "List.h"
using namespace std;
//
#include "Edge.h"
#include "quickSort.h"

//void main() {
//	vector<Edge> v;
//	Edge tmp1(1, 3, 2, nullptr, nullptr);
//	Edge tmp2(2, 5, -3, nullptr, nullptr);
//	Edge tmp3(4, 5, 9, nullptr, nullptr);
//	Edge tmp4(3, 2, 0, nullptr, nullptr);
//	v.push_back(tmp1);
//	v.push_back(tmp2);
//	v.push_back(tmp3);
//	v.push_back(tmp4);
//
//	quickSort(v, 0, 3);
//
//}
MST Kruskal(Graph& g) {
	MST F;
	DisjointSets UF(g.getGraphSize());
	
	for (int i = 1; i <= g.getGraphSize(); i++)
		UF.MakeSet(i);
	
	if (!g.getSorted()) {
		quickSort(g.getListOfEdges(), 0, g.getNumOfEdges() - 1);
		g.setSorted();
	}

	for (auto& element : g.getListOfEdges()) {
		int u1 = UF.Find(element.getU());
		int v1 = UF.Find(element.getV());
		if (u1 != v1) 
		{
			UF.UnionBySize(u1, v1);
			F.addEdge(element);
		}
	}
	return F;
}

MST Prim(Graph &G) {
	int n = G.getGraphSize();
	MST T;
	PriorityQueue Q;
	vector<bool> InT;
	vector<int> min;
	vector<int> p;
	
	// adding dummy
	min.push_back(-1);
	InT.push_back(false);
	p.push_back(-1);
	
	min.push_back(0);
	InT.push_back(false);
	p.push_back(-1);
	for (int i = 1; i < n; i++)
	{
		InT.push_back(false);
		p.push_back(0);
		min.push_back(INT32_MAX);
	};
	Q.Build(n, min);
	while (!Q.IsEmpty())
	{
		Pair u = Q.DeleteMin();
		if (u.data != 1) {
			Edge edge(u.data, p[u.data], u.key, nullptr, nullptr);
			T.addEdge(edge);
		}
		InT[u.data] = true;
		List& adjList = G.GetAdjList(u.data);
		Edge* curr = adjList.getHead(), * next;
		while (curr != nullptr) {
			int v = curr->getV();
			int weight = curr->getWeight();
			if (!InT[v] && weight < min[v])
			{
				min[v] = weight;
				p[v] = curr->getU();
				Q.DecreaseKey(v, min[v]);
			}
			next = curr->getNext();
			curr = next;
		}
	}
	return T;
}

void main(int argc, char* argv[]){
	ifstream myfile;
	myfile.open (argv[1]);
	
	string line;
	getline(myfile, line);
	Graph g;
	g.MakeEmptyGraph(stoi(line)); //possible error, line is not a valid number!
	getline(myfile, line);
	int m = stoi(line);
	/*char* edge = nullptr;*/
	for (int i=0; i<m; ++i)
	{
		//check if there are excatly m edges in file
		getline(myfile, line);
		istringstream iss(line);
		string token;
		vector <int> v;
		while (getline(iss, token, ' '))
		{
			v.push_back(stoi(token));
		}
		if (v.size() != 3) {
			cout << "Invalid input!";
			exit(1);
		}
		if (v[0] <1 || v[0] > g.getGraphSize())
		{
			cout << "Invalid input!";
			exit(1);	
		}
		if (v[1] <1 || v[1] > g.getGraphSize())
		{
			cout << "Invalid input!";
			exit(1);			
		}
		g.AddEdge(v[0], v[1], v[2]);
		v.clear();
	}

	MST tmp1 = Kruskal(g);
	MST tmp2 = Prim(g);

	getline(myfile, line);
	istringstream iss(line);
	string token;
	vector <int> v;
	while (getline(iss, token, ' '))
	{
		v.push_back(stoi(token));
	}
	if (v.size() != 2) {
		cout << "Invalid input!";
		exit(1);
	}
	if (v[0] <1 || v[0] > g.getGraphSize())
	{
		cout << "Invalid input!";
		exit(1);	
	}
	if (v[1] <1 || v[1] > g.getGraphSize())
	{
		cout << "Invalid input!";
		exit(1);			
	}
	myfile.close();
	g.RemoveEdge(v[0], v[1]);
	Kruskal(g);
	

	
}



