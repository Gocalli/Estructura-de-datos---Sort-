#include "countingSort.h"
#include "funcionesGlobales.h"

#include <iostream>
using namespace std;

// falta todo
void countSort(int array[], int size) {
    int output[size];  
    int max = array[0]; 

   
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    
    int count[max + 1] = {0}; 

   
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

   
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

   
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--; 
    }

   
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}


int callCounting() {
    int n;

   
    cout << "Ingrese el tamaño del array: ";
    cin >> n;

    int array[n]; 

    
    cout << "Ingrese " << n << " elementos:\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

   
    countSort(array, n);

    
    cout << "Array ordenado: ";
    printArray(array, n);

    return 0;
}