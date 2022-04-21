#include "Graph.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DisjointSets.h"

using namespace std;

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

	// kruskal, prim

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

vector<Edge> Kruskal(Graph &g) {
	vector <Edge> F;
	DisjointSets UF(g.getGraphSize());
	for (int i = 1; i <= g.getGraphSize(); i++) {
		UF.MakeSet(i);
	}
	vector <Edge> L;
	for (int i = 0; i < g.getGraphSize(); i++) {

	}




	return F;
}

