#pragma once
#include <iostream>
using namespace std;
#include <vector>

struct Tree {
	int size, parent;
};

class DisjointSets
{
public:
	DisjointSets(int size = 0);
	~DisjointSets();
	int Find(int u);
	void UnionBySize(int u, int v);
	void MakeSet(int v);

private:
	vector<Tree> m_forest;
};

