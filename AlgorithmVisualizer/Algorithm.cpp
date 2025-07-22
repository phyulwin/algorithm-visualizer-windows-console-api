// Created by Phyu H. Lwin on July 22, 2025

#include "Algorithm.h"

void Algorithm::visualizeBubbleSort(vector<int>& arr) {
    int steps = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            ++steps;
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
