#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <fstream>
#include <chrono>

void Swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
// void quicksortIterativo(int arr[], int low, int high);
int callQuick();

#endif