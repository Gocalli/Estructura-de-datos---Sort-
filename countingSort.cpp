#include "countingSort.h"
#include "funcionesGlobales.h"
#include <iostream>
#include <sys/timeb.h> 
#include <fstream>
#include <sstream>

using namespace std;

void ordenarConteo(int array[], int size) {
    int salida[size];  
    int max = array[0]; 

    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int conteo[max + 1] = {0}; 

    for (int i = 0; i < size; i++) {
        conteo[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        conteo[i] += conteo[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        salida[conteo[array[i]] - 1] = array[i];
        conteo[array[i]]--; 
    }

    for (int i = 0; i < size; i++) {
        array[i] = salida[i];
    }
}

int ejecutarCounting() {
    int opcion;
    cout << "Seleccione el modo de entrada:\n";
    cout << "1. Ingresar valores manualmente\n";
    cout << "2. Leer desde archivo\n";
    cin >> opcion;

    int *array = nullptr;
    int size = 0;

    if (opcion == 1) {
        cout << "Ingrese el tamaño del array: ";
        cin >> size;
        array = new int[size];
        cout << "Ingrese los elementos:\n";
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }
    } else if (opcion == 2) {
        ifstream archivo("array.txt");
        if (!archivo) {
            cout << "Error: No se pudo abrir el archivo." << endl;
            return 1;
        }
        archivo >> size;
        array = new int[size];
        for (int i = 0; i < size; i++) {
            archivo >> array[i];
        }
        archivo.close();
    } else {
        cout << "Opción no válida." << endl;
        return 1;
    }

    cout << "--- El Array original fue: \n";
    mostrarArray(array, size);

    struct timeb inicio, fin;
    ftime(&inicio);  

    ordenarConteo(array, size);

    ftime(&fin);
    int tiempoTotal = (int)(1000 * (fin.time - inicio.time) + (fin.millitm - inicio.millitm));

    cout << "--- El Array ordenado es:\n";
    mostrarArray(array, size);
    cout << "--- Tiempo de ejecución: " << tiempoTotal << " ms" << endl;

    delete[] array;
    return 0;
}
