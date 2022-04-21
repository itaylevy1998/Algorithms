#include "Graph.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DisjointSets.h"
#include "MST.h"
#include "PriorityQueue.h"
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
	for (int i = 1; i <= g.getGraphSize(); i++) {
		UF.MakeSet(i);
	}
	quickSort(g.getListOfEdges(), 0, g.getNumOfEdges() - 1);
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

void Prim(Graph G) {
	int n = G.getGraphSize();
	PriorityQueue Q;
	vector<bool> InT;
	vector<int> min;
	vector<int> p;
	min.push_back(0);
	InT.push_back(false);
	p.push_back(0);
	for (int i = 1; i < n; i++)
	{
		InT.push_back(false);
		p.push_back(0);
		min.push_back(0); //infinity
	};
	
	Q.Build(n, min);
	return;
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
	MST tmp = Kruskal(g);
	// kruskal, prim
	Prim(g);

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
	// kruskal
	
}



