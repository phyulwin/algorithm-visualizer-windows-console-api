/*
*
* Created by Phyu H. Lwin on July 22, 2025
*
*/

// AlgorithmVisualizer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Algorithm.h"


int main()
{
    vector<int> arr = { 5, 3, 8, 1, 2 };
    int choice;

    cout << "=== Algorithm Visualizer ===" << endl;
    cout << "1. Bubble Sort" << endl;
    
    cout << "Choose an algorithm to visualize: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Time Complexity (Bubble Sort): O(n^2)" << endl;
        Algorithm::visualizeBubbleSort(arr);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    system("pause");
    return 0;
}
