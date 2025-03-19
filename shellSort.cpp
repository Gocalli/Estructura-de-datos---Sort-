#include "shellSort.h"
#include "funcionesGlobales.h"

using namespace std;

#define MAX_SIZE 100

void shellSort(int arr[], int n) {
    auto start = chrono::high_resolution_clock::now();
    int gap = n / 2;
    while (gap > 0) {
        cout << "\n[Inicio de la iteración con gap = " << gap << "]" << endl;
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                cout << "Intercambiando " << arr[j] << " con " << arr[j - gap] << endl;
                arr[j] = arr[j - gap];
                j -= gap;
                
                cout << "Paso: ";
                for (int k = 0; k < n; k++) cout << arr[k] << " ";
                cout << endl;
            }
            arr[j] = temp;
            cout << "Colocando " << temp << " en su lugar: ";
            for (int k = 0; k < n; k++) cout << arr[k] << " ";
            cout << endl;
        }
        gap /= 2;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\nTiempo de ejecución: " << duration.count() << " ms" << endl;
}



int leerArregloDesdeArchivo(const char* filename, int arr[], int& n) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return -1;
    }
    n = 0;
    while (file >> arr[n] && n < MAX_SIZE) n++;
    file.close();
    return n;
}

void leerArregloDesdeEntrada(int arr[], int& n) {
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> n;
    if (n > MAX_SIZE) {
        cout << "Error: Tamaño máximo permitido es " << MAX_SIZE << endl;
        n = MAX_SIZE;
    }
    cout << "Ingrese los " << n << " elementos: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

int callShell() {
    int arr[MAX_SIZE], n = 0, opcion;
    cout << "Seleccione la forma de ingresar el arreglo:" << endl;
    cout << "1. Desde un archivo (array.txt)\n2. Ingresar manualmente\n3. Usar un arreglo predefinido\nOpción: ";
    cin >> opcion;

    if (opcion == 1) {
        if (leerArregloDesdeArchivo("array.txt", arr, n) == -1) return 1;
    } else if (opcion == 2) {
        leerArregloDesdeEntrada(arr, n);
    } else if (opcion == 3) {
        int predefinido[] = {5, 2, 9, 1, 5, 6};
        n = sizeof(predefinido) / sizeof(predefinido[0]);
        for (int i = 0; i < n; i++) arr[i] = predefinido[i];
    } else {
        cout << "Opción no válida." << endl;
        return 1;
    }

    cout << "Arreglo original: ";
    printArray(arr, n);
    shellSort(arr, n);
    cout << "\nArreglo ordenado: ";
    printArray(arr, n);
    return 0;
}
