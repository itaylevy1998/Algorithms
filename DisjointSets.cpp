#include "DisjointSets.h"

// constructor
DisjointSets::DisjointSets(int size)
{
	
	for (int i = 0; i < size + 1; ++i) 
	{
		Tree tmp;
		tmp.parent = -1;
		tmp.size = 0;
		m_forest.push_back(tmp);
	}
}

//destructor
DisjointSets::~DisjointSets()
{
	m_forest.clear();
}

// find the parent of the given node
int DisjointSets::Find(int v)
{
	if (m_forest[v].parent == v)
		return v;

	else {
		int root = Find(m_forest[v].parent);
		m_forest[v].parent = root;
		return root;
	}
}

// unite two sets into one sets - not sure about it
void DisjointSets::UnionBySize(int u, int v) {

	int pu = Find(u);
	int pv = Find(v);

	if (m_forest[pu].size > m_forest[pv].size)
	{
		m_forest[v].parent = m_forest[u].parent;
		m_forest[pu].size += m_forest[pv].size;
	}

	else {
		m_forest[u].parent = m_forest[v].parent;
		m_forest[pv].size += m_forest[pu].size;
	}
}

// create new set
void DisjointSets::MakeSet(int v) 
{
	if (m_forest.size() <= v)
		m_forest.resize(v + 2);

	m_forest[v].size = 1;
	m_forest[v].parent = v;
}