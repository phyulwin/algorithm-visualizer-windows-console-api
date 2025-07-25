/*
*
* Created by Phyu H. Lwin on July 22, 2025
*
*/

// AlgorithmVisualizer.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "Menu.h"

int main() {
    char again;
    do {
        vector<int> arr = { 5, 3, 8, 1, 2 };
        Menu::displayMenu(arr);
        cout << "Run another algorithm? (y/n): ";
        cin >> again;
        cin.ignore();
    } while (tolower(again) == 'y');

    return 0;
}