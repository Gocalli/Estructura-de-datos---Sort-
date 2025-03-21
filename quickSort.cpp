#include "quickSort.h"
#include "funcionesGlobales.h"
using namespace std;
using namespace std::chrono; // Usar el namespace de chrono

// Función para intercambiar elementos
void Swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Función para imprimir el arreglo
// void printArray(int array[], int size) {
//     for (int i = 0; i < size; i++)
//         cout << array[i] << " ";
//     cout << endl;
// }

// Función para reorganizar el arreglo (encontrar el punto de partición)
int partition(int array[], int low, int high) {
    // Seleccionar el elemento más a la derecha como pivote
    int pivot = array[high];

    // Puntero para el elemento mayor
    int i = (low - 1);

    // Recorrer cada elemento del arreglo y compararlo con el pivote
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            // Si se encuentra un elemento menor que el pivote
            // intercambiarlo con el elemento mayor señalado por i
            i++;
         Swap(&array[i], &array[j]);
        }
    }

    // Intercambiar el pivote con el elemento mayor en i
 Swap(&array[i + 1], &array[high]);

    // Devolver el punto de partición
    return (i + 1);
}

// Función QuickSort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Encontrar el elemento pivote
        int pi = partition(array, low, high);

        // Llamada recursiva a la izquierda del pivote
        quickSort(array, low, pi - 1);

        // Llamada recursiva a la derecha del pivote
        quickSort(array, pi + 1, high);
    }
}

// Código principal
int callQuick() {
    // Abrir el archivo
    ifstream inputFile("array.txt");

    // Verificar si el archivo se abrió correctamente
    if (!inputFile.is_open()) {
        cout << "--- Error: No se pudo abrir el archivo.\n" << endl;
        return 1; // Salir del programa con código de error
    }

    // Leer el tamaño del arreglo
    int size;
    inputFile >> size;

    // Crear un arreglo dinámico
    int *array = new int[size];

    // Leer los elementos del arreglo desde el archivo
    for (int i = 0; i < size; i++) {
        inputFile >> array[i];
    }

    // Cerrar el archivo
    inputFile.close();

    // Iniciar el reloj (medir el tiempo antes de ordenar)
    auto start = high_resolution_clock::now();

    // Ejecutar QuickSort
    quickSort(array, 0, size - 1);

    // Detener el reloj (medir el tiempo después de ordenar)
    auto stop = high_resolution_clock::now();

    // Calcular la duración en microsegundos
    auto duration = duration_cast<microseconds>(stop - start);

    // Imprimir el arreglo ordenado
    cout << "Arreglo ordenado en orden ascendente:\n";
    printArray(array, size);

    // Imprimir el tiempo de ejecución
    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos." << endl;

    // Liberar la memoria del arreglo dinámico
    delete[] array;

    return 0;
}