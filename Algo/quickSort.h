#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "Edge.h"

void swap(Edge* x, Edge* y);
int partition(vector<Edge>& arr, int left, int right);
void quickSort(vector<Edge>& arr, int left, int right);

