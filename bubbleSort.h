#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

int bubbleSort(int array[], int size, bool debugMode);
bool readArrayFromFile(int array[], int &size, const int &filename);
int callBubble();

#endif