/*
*
* Created by Phyu H. Lwin on July 22, 2025
* 
*/

#ifndef HELPER_H
#define HELPER_H

#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <thread>   // for sleep
#include <chrono>   // for delay
using namespace std;

class Helper
{
public:
    static void setCursor(int x, int y);
    static void setColor(int color);
    static void printArray(const vector<int>& arr, int highlight = -1);
};

#endif //HELPER_H