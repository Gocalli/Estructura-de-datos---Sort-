#include "funcionesGlobales.h"
#include "shellsort.h"
using namespace std;
void shellSort(int arr[], int n) {
   
    int gap = n / 2;

// Le falta todo esto    

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; 
            int j = i;

           
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            
            arr[j] = temp;
        }
        
        gap /= 2;
    }
}

int callShell() {
    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    
    int* arr = new int[n];

    
    cout << "Ingrese los numeros, uno por uno:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }

   
    cout << "\nArreglo original: ";
    printArray(arr, n);

    
    shellSort(arr, n);

    
    cout << "Arreglo ordenado: ";
    printArray(arr, n);

    
    delete[] arr;

    return 0;
}