#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <iomanip> 
#include <ctime>
#include <fstream>

int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void quicksortIterativo(int arr[], int low, int high);
int callQuick();

#endif