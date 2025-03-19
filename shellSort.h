#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <fstream>
#include <chrono>

void shellSort(int arr[], int n);
int leerArregloDesdeArchivo(const char* archivo, int arr[], int& n);
void leerArregloDesdeEntrada(int arr[], int& n);
int callShell();

#endif