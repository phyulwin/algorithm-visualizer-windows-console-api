#include "Menu.h"

void Menu::displayMenu(vector<int>& arr) {
    /*vector<int> arr = { 5, 3, 8, 1, 2 };*/
    int choice;

    cout << "=== Algorithm Visualizer ===" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Fibonacci (DP)" << endl;
    cout << "7. 0/1 Knapsack (DP)" << endl;
    cout << "8. Depth-First Search (DFS)" << endl;
    cout << "9. Breadth-First Search (BFS)" << endl;

    cout << "Choose an algorithm to visualize: ";

    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Time Complexity (Bubble Sort): O(n^2)" << endl;
        Algorithm::visualizeBubbleSort(arr);
        cout << endl; 
        cin.clear(); while (cin.get() != '\n' && !cin.eof());
        break;
    case 2:
        cout << "Time Complexity (Selection Sort): O(n^2)" << endl;
        Algorithm::visualizeSelectionSort(arr);
        cin.clear(); while (cin.get() != '\n' && !cin.eof());
        break;
    case 3:
        cout << "Time Complexity (Insertion Sort): O(n^2)" << endl;
        Algorithm::visualizeInsertionSort(arr);
        cin.clear(); while(cin.get() != '\n' && !cin.eof());
        break;
    case 4:
        cout << "Time Complexity (Merge Sort): O(n log n)" << endl;
        Algorithm::visualizeMergeSort(arr);
        cin.clear(); while (cin.get() != '\n' && !cin.eof());
        break;
    case 5:
        cout << "Time Complexity (Quick Sort): O(n log n)" << endl;
        Algorithm::visualizeQuickSort(arr);
        cin.clear(); while (cin.get() != '\n' && !cin.eof());
        break;
    case 6:
    {
        int n;
        cout << "Enter n for Fibonacci: ";
        cin >> n;
        Algorithm::visualizeFibonacciDP(n);
        cin.clear(); while (cin.get() != '\n' && !cin.eof());
        break;
    }
    case 7:
    {
        vector<int> weights = { 1, 3, 4, 5 };
        vector<int> values = { 1, 4, 5, 7 };
        int capacity = 7;
        cout << "Solving 0/1 Knapsack (items=4, capacity=7):\n";
        Algorithm::visualizeKnapsackDP(weights, values, capacity);
        cin.clear();  while (cin.get() != '\n' && !cin.eof());
        break;
    }
    case 8: {
        vector<vector<int>> adj = {
            {},          // 0 (unused)
            {2, 3},      // 1
            {4},         // 2
            {5},         // 3
            {},          // 4
            {}           // 5
        };
        Algorithm::visualizeDFS(1, adj);
        break;
    }
    case 9: {
        vector<vector<int>> adj = {
            {},          // 0 (unused)
            {2, 3},      // 1
            {4},         // 2
            {5},         // 3
            {},          // 4
            {}           // 5
        };
        Algorithm::visualizeBFS(1, adj);
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    //system("pause");
    cin.ignore();
    cin.get();
}