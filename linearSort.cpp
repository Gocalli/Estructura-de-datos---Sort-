#include "linearSort.h"
#include "funcionesGlobales.h"


using namespace std;

int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int arrayPredefinido() {
    int array[] = {2, 4, 0, 1, 9};
    int x;
    int n = sizeof(array) / sizeof(array[0]);
    
    cout << "Ingrese el número a buscar: ";
    cin >> x;
    
    clock_t start = clock();
    int result = linearSearch(array, n, x);
    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;
    
    (result == -1) ? cout << "Elemento no encontrado\n" : cout << "Elemento encontrado en la posición: " << result << endl;
    cout << "Tiempo de búsqueda: " << tiempo << " segundos" << endl;
    
    return 0;
}

int ingresarArray() {
    int sizeArrayUser;
    cout << "Ingrese el tamaño del array: ";
    cin >> sizeArrayUser;
    
    int* array = new int[sizeArrayUser];
    
    cout << "Ingrese los números en el array:\n";
    for (int i = 0; i < sizeArrayUser; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> array[i];
    }
    
    cout << "El array ingresado es: { ";
    for (int i = 0; i < sizeArrayUser; i++) {
        cout << array[i] << " ";
    }
    cout << "}\n";
    
    int x;
    cout << "Ingrese el número a buscar: ";
    cin >> x;
    
    clock_t start = clock();
    int result = linearSearch(array, sizeArrayUser, x);
    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;
    
    (result == -1) ? cout << "Elemento no encontrado\n" : cout << "Elemento encontrado en la posición: " << result << endl;
    cout << "Tiempo de búsqueda: " << tiempo << " segundos" << endl;
    
    delete[] array;
    return 0;
}

int leerArrayDesdeArchivo() {
    ifstream archivo("array.txt");
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo array.txt\n";
        return -1;
    }
    
    int sizeArray;
    archivo >> sizeArray;
    int* array = new int[sizeArray];
    
    for (int i = 0; i < sizeArray; i++) {
        archivo >> array[i];
    }
    archivo.close();
    
    cout << "El array leído del archivo es: { ";
    for (int i = 0; i < sizeArray; i++) {
        cout << array[i] << " ";
    }
    cout << "}\n";
    
    int x;
    cout << "Ingrese el número a buscar: ";
    cin >> x;
    
    clock_t start = clock();
    int result = linearSearch(array, sizeArray, x);
    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;
    
    (result == -1) ? cout << "Elemento no encontrado\n" : cout << "Elemento encontrado en la posición: " << result << endl;
    cout << "Tiempo de búsqueda: " << tiempo << " segundos" << endl;
    
    delete[] array;
    return 0;
}

int linearCall() {
    int opcion;
    do {
        cout << "Menú Linear Search\n";
        cout << "1. Array Predefinido\n";
        cout << "2. Ingresar Array\n";
        cout << "3. Leer Array desde archivo (array.txt)\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                arrayPredefinido();
                break;
            case 2:
                ingresarArray();
                break;
            case 3:
                leerArrayDesdeArchivo();
                break;
            default:
                cout << "Opción no válida, intente nuevamente.\n";
        }
    } while (opcion < 1 || opcion > 3);
    
    return 0;
}