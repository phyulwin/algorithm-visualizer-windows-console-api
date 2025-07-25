// Created by Phyu H. Lwin on July 22, 2025

#include "Algorithm.h"

void Algorithm::visualizeBubbleSort(vector<int>& arr) {
    int steps = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            ++steps;
            system("cls"); // Clear console
            Helper::printArray(arr, j);
            cout << "Steps: " << steps << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
    Helper::printArray(arr);
    cout << "Total Steps: " << steps << endl;
    Helper::setColor(7); // reset color
    

    cout << "Time Complexity (Bubble Sort): O(n^2)" << endl;
}

void Algorithm::visualizeSelectionSort(vector<int>& arr) {
    int steps = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            ++steps; 
            system("cls"); // Clear console
            Helper::printArray(arr, j);
            cout << "Steps: " << steps << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    Helper::printArray(arr);
    cout << "Total Steps: " << steps << endl;
    cout << "Time Complexity (Selection Sort): O(n^2)" << endl;
    Helper::setColor(7);
}

void Algorithm::visualizeInsertionSort(vector<int>& arr) {
    int steps = 0;
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            ++steps;
            arr[j + 1] = arr[j];
            system("cls"); // Clear console
            Helper::printArray(arr, j);
            cout << "Steps: " << steps << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            --j;
        }
        arr[j + 1] = key;
    }
    Helper::printArray(arr);
    cout << "Total Steps: " << steps << endl;
    cout << "Time Complexity (Insertion Sort): O(n^2)" << endl;
    Helper::setColor(7);
}

// Merge Sort Implementation
void merge(vector<int>& arr, int l, int m, int r, int& steps) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        ++steps;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        system("cls"); // Clear console
        Helper::printArray(arr, k - 1);
        cout << "Steps: " << steps << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r, int& steps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, steps);
        mergeSort(arr, m + 1, r, steps);
        merge(arr, l, m, r, steps);
    }
}

void Algorithm::visualizeMergeSort(vector<int>& arr) {
    int steps = 0;
    mergeSort(arr, 0, arr.size() - 1, steps);
    Helper::printArray(arr);
    cout << "Total Steps: " << steps << endl;
    cout << "Time Complexity (Merge Sort): O(n log n)" << endl;
    Helper::setColor(7);
}

// Quick Sort Implementation
int partition(vector<int>& arr, int low, int high, int& steps) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        ++steps;
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
        system("cls"); // Clear console
        Helper::printArray(arr, j);
        cout << "Steps: " << steps << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& steps) {
    if (low < high) {
        int pi = partition(arr, low, high, steps);
        quickSort(arr, low, pi - 1, steps);
        quickSort(arr, pi + 1, high, steps);
    }
}

void Algorithm::visualizeQuickSort(vector<int>& arr) {
    int steps = 0;
    quickSort(arr, 0, arr.size() - 1, steps);
    Helper::printArray(arr);
    cout << "Total Steps: " << steps << endl;
    cout << "Time Complexity (Quick Sort): O(n log n)" << endl;
    Helper::setColor(7);
}

// Fibonacci Dynamic Programming Implementation
void Algorithm::visualizeFibonacciDP(int n) {
    vector<int> dp(n + 1, 0);
    int steps = 0;

    dp[0] = 0;
    if (n > 0) dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        ++steps;
        dp[i] = dp[i - 1] + dp[i - 2];
        system("cls"); // Clear console
        Helper::printArray(dp, i);
        cout << "Steps: " << steps << "  -> Fib(" << i << ") = " << dp[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "Fibonacci(" << n << ") = " << dp[n] << endl;
    cout << "Time Complexity (DP): O(n)" << endl;
    Helper::setColor(7);
}

// Knapsack Dynamic Programming Implementation
void Algorithm::visualizeKnapsackDP(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    int steps = 0;

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            ++steps;
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
            system("cls"); // Clear console
            cout << "Step: " << steps << " | dp[" << i << "][" << w << "] = " << dp[i][w] << endl;
            this_thread::sleep_for(chrono::milliseconds(300));
        }
    }

    cout << "Max Value: " << dp[n][capacity] << endl;
    cout << "Time Complexity: O(n * W)" << endl;
    Helper::setColor(7);
}
// Note: The weights and values vectors should be passed as arguments to the function.

// dfs (depth -first search) implementation
void dfsUtil(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& steps) {
    visited[node] = true;
    ++steps;
    system("cls"); // Clear console
    cout << "Visited: " << node << " | Step: " << steps << endl;
    Helper::setColor(10);
    this_thread::sleep_for(chrono::milliseconds(500));

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, steps);
        }
    }
}

void Algorithm::visualizeDFS(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    int steps = 0;
    cout << "Starting DFS from node " << start << "...\n";
    dfsUtil(start, adj, visited, steps);
    cout << "DFS Complete. Total Steps: " << steps << endl;
    Helper::setColor(7);
}

// bfs (breadth-first search) implementation
void Algorithm::visualizeBFS(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    int steps = 0;

    visited[start] = true;
    q.push(start);

    cout << "Starting BFS from node " << start << "...\n";

    while (!q.empty()) {
        int node = q.front(); q.pop();
        ++steps;
        system("cls"); // Clear console
        cout << "Visited: " << node << " | Step: " << steps << endl;
        Helper::setColor(11);
        this_thread::sleep_for(chrono::milliseconds(500));

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << "BFS Complete. Total Steps: " << steps << endl;
    Helper::setColor(7);
}