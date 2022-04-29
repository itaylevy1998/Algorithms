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
#include "DFS.h"
#include "Edge.h"
#include "quickSort.h"
using namespace std;

MST Kruskal(Graph& g);
MST Prim(Graph& G);
void printErrorMessage(ofstream& file);
void processLine(ofstream& outputFile, ifstream& inputFile, vector<int>& fileParameters,int numOfParameters);
void printInfoToScreenAndFile(ofstream& outputFile, string output);


void main(int argc, char* argv[]) {

	ifstream inputFile;
	ofstream outputFile;
	string line;
	Graph g;
	vector <int> fileParameters;
	outputFile.open(argv[2]);
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
		printErrorMessage(outputFile);

	//get num of vertex
	processLine(outputFile, inputFile, fileParameters, 1);
	g.MakeEmptyGraph(fileParameters[0]);
	fileParameters.clear();


	//get num of edges
	processLine(outputFile, inputFile, fileParameters, 1);
	int m = fileParameters[0];
	fileParameters.clear();

	// get edges
	for (int i = 0; i < m; ++i) {
		processLine(outputFile, inputFile, fileParameters, 3);

		if (fileParameters[0] <1 || fileParameters[0] > g.getGraphSize())
			printErrorMessage(outputFile);
	
		if (fileParameters[1] <1 || fileParameters[1] > g.getGraphSize())
			printErrorMessage(outputFile);

		g.AddEdge(fileParameters[0], fileParameters[1], fileParameters[2]);

		fileParameters.clear();
	}

	//get edge to remove
	processLine(outputFile, inputFile, fileParameters, 2);
	if (fileParameters[0] <1 || fileParameters[0] > g.getGraphSize())
			printErrorMessage(outputFile);

	inputFile.close();

	if (fileParameters[1] <1 || fileParameters[1] > g.getGraphSize())
			printErrorMessage(outputFile);


	// if g isn't connective - invalid input
	if (!isConnective(g))
		printErrorMessage(outputFile);
	
	MST tmp1 = Kruskal(g);
	printInfoToScreenAndFile(outputFile, "Kruskal " + to_string(tmp1.getWeight()));

	MST tmp2 = Prim(g);
	printInfoToScreenAndFile(outputFile, "Prim " + to_string(tmp2.getWeight()));
	try {
		g.RemoveEdge(fileParameters[0], fileParameters[1]);
	}
	catch (...) {
		printErrorMessage(outputFile);
	}
	

	if (isConnective(g)) {
		if (tmp1.isEdgeInMst(fileParameters[0], fileParameters[1])) {
			MST tmp3 = Kruskal(g);
			printInfoToScreenAndFile(outputFile, "Kruskal " + to_string(tmp3.getWeight()));
		}
		else
			printInfoToScreenAndFile(outputFile, "Kruskal " + to_string(tmp1.getWeight()));
	}
	else
		printInfoToScreenAndFile(outputFile, "no MST");

	outputFile.close();
}

void processLine(ofstream& outputFile, ifstream& inputFile, vector<int>& fileParameters,int numOfParameters){

	string line;
	try {
		getline(inputFile, line);
	}
	catch (...){
		printErrorMessage(outputFile);
	}
	// exception
	istringstream iss(line);
	string token;
	int i = 0, j = 0;
	while (getline(iss, token, ' '))
	{
		for (int i = 0; i < token.size(); i++) {
			if (j == 2) {
				if (i == 0) {
					if (!isdigit(token[0]) && token[0]!= '-')
						printErrorMessage(outputFile);
				}
				else {
					if (!isdigit(token[i]))
						printErrorMessage(outputFile);
				}
			}
			else {
				if (!isdigit(token[i]))
					printErrorMessage(outputFile);
			}
		}
		fileParameters.push_back(stoi(token));
		j++;
	}
	if (fileParameters.size() != numOfParameters) {
		printErrorMessage(outputFile);
	}
}

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

MST Prim(Graph& G) {
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

void printErrorMessage(ofstream& file) {
	cout << "Invalid Input!";
	file << "Invalid Input!";
	file.close();
	exit(1);
}

void printInfoToScreenAndFile(ofstream& outputFile, string output) {
	cout << output << endl;
	outputFile << output << endl;
}