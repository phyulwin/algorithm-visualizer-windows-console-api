// Created by Phyu H. Lwin on July 22, 2025

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <queue>

#include "Helper.h"

using namespace std;

class Algorithm
{
public:
    static void visualizeBubbleSort(vector<int>& arr);
    static void visualizeSelectionSort(vector<int>& arr);
    static void visualizeInsertionSort(vector<int>& arr);
    static void visualizeMergeSort(vector<int>& arr);
    static void visualizeQuickSort(vector<int>& arr);
    static void visualizeFibonacciDP(int n);
    static void visualizeKnapsackDP(const vector<int>& weights, const vector<int>& values, int capacity);

    // add graph traversal visualizers: DFS and BFS step-by-step
    static void visualizeDFS(int start, const vector<vector<int>>& adj);
    static void visualizeBFS(int start, const vector<vector<int>>& adj);

};

#endif //ALGORITHM_H