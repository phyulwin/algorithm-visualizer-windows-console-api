/*
*
* Created by Phyu H. Lwin on July 22, 2025
*
*/

#include "Helper.h"

void Helper::setCursor(int x, int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(h, pos);
}

void Helper::setColor(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

void Helper::printArray(const vector<int>& arr, int highlight) {
    setCursor(0, 2); // position output
    for (int i = 0; i < arr.size(); ++i) {
        if (i == highlight) setColor(12); // red
        else setColor(7);                 // white
        cout << arr[i] << " ";
    }
    cout << endl;
}