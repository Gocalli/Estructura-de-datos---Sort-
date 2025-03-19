#include "quickSort.h"
#include "funcionesGlobales.h"
#

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void quicksortIterativo(int arr[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;
    
    stack[++top] = low;
    stack[++top] = high;
    
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        
        int pi = partition(arr, low, high);
        
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

int callQuick() {
    int opcion;
    
    while (true) {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Ordenar con Quicksort Recursivo\n";
        cout << "2. Ordenar con Quicksort Iterativo\n";
        cout << "3. Ordenar desde archivo array.txt\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        if (opcion == 4) {
            cout << "Saliendo del programa...\n";
            break;
        }
        
        int n;
        int arr[1000];
        
        if (opcion == 3) {
            ifstream inputFile("array.txt");
            if (!inputFile) {
                cout << "Error al abrir el archivo.\n";
                continue;
            }
            inputFile >> n;
            for (int i = 0; i < n; i++) inputFile >> arr[i];
            inputFile.close();
        } else {
            cout << "Ingrese el tamaño del arreglo (máx 1000): ";
            cin >> n;
            
            if (n <= 0 || n > 1000) {
                cout << "Tamaño inválido. Intente nuevamente.\n";
                continue;
            }
            
            cout << "Ingrese los elementos del arreglo: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        }
        
        clock_t start, end;
        if (opcion == 1) {
            start = clock();
            quicksort(arr, 0, n - 1);
            end = clock();
            cout << "Array ordenado (Recursivo): ";
        } else if (opcion == 2) {
            start = clock();
            quicksortIterativo(arr, 0, n - 1);
            end = clock();
            cout << "Array ordenado (Iterativo): ";
        } else {
            cout << "Opción inválida. Intente de nuevo.\n";
            continue;
        }
        
        printArray(arr, n);
        cout << "Tiempo de ejecución: " << scientific << double(end - start) / CLOCKS_PER_SEC << " segundos\n";
    }
    
    return 0;
}