#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "Graph.h"

extern int white;
extern int grey;
extern int black;

bool isConnective(Graph& g);
void Visit(vector<int>& Color, Graph& g, int u);