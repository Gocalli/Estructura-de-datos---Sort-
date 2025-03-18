#include "funcionesGlobales.h"
#include "linearSort.h"

using namespace std;

// le falta datos por archivo
int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int ArrayEstablecido() {
    int array[] = {2, 4, 0, 1, 9};
    int x = 0;
    int n = sizeof(array) / sizeof(array[0]);
    int result = linearSearch(array, n, x);
    
    (result == -1) ? cout << "Element not found\n" : cout << "Element found at index: " << result << endl;
    
    return 0;
}

int EstablecerArray() {
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
    cout << "Qué número del array quiere encontrar: ";
    cin >> x;

    int result = linearSearch(array, sizeArrayUser, x);
    
    
    (result == -1) ? cout << "Element not found\n" : cout << "Element found at index: " << result << endl;
    
   
    delete[] array;

    return 0;
}

int linearcall() {
    int opcion;
    cout << "Menú Linear Search\n";
    cout << "1. Array Establecido\n";
    cout << "2. Establecer Array\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            ArrayEstablecido();
            break;
        case 2:
            EstablecerArray();
            break;
        default:
            cout << "Opción no válida\n";
            break;
    }

    return 0;
}