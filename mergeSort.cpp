#include "mergeSort.h"
#include "funcionesGlobales.h"

using namespace std;
using namespace std::chrono;



void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else array[k++] = R[j++];
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];
}


void mergeSortHelper(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(array, left, mid);
        mergeSortHelper(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}


void mergeSort(int array[], int size) {
    mergeSortHelper(array, 0, size - 1);
}

void merge_sort() {
    cout << "--- Seleccione el modo de entrada ---\n";
    cout << "1. Array quemado\n2. Array por teclado\n3. Array por archivo\n";

    int mode;
    cin >> mode;

    int data[100]; 
    int size = 0;

    if (mode == 1) {
        
        int temp[] = {20, 12, 10, 15, 2};
        size = sizeof(temp) / sizeof(temp[0]);
        for (int i = 0; i < size; i++) {
            data[i] = temp[i];
        }

    } else if (mode == 2) {
        
        cout << "Ingrese el tamaño del array: ";
        cin >> size;
        cout << "Ingrese los elementos:\n";
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }

    } else if (mode == 3) {
       
        ifstream inputFile("array.txt");
        if (!inputFile) {
            cout << "Error al abrir el archivo.\n";
            return;
        }
        inputFile >> size;
        for (int i = 0; i < size; i++){ 
            inputFile >> data[i];
        }
        inputFile.close();
    } else {
        cout << "Opción inválida.\n";
        return;
    }

   
    cout << "\n--- Array original ---\n";
    printArray(data, size);

    
    auto start = high_resolution_clock::now();

    mergeSort(data, size);

    auto stop = high_resolution_clock::now();

    
    cout << "\n--- Array ordenado ---\n";
    printArray(data, size);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "--- Tiempo de ejecución: " << duration.count() << " microsegundos\n";
}


int callMerge() {
    merge_sort();
    return 0;
}
