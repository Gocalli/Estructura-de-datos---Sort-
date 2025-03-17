#include "bubblesort.h"
#include "funcionesGlobales.h"


using namespace std;
using namespace std::chrono;





int bubbleSort(int array[], int size, bool debugMode) {
    int totalSteps = 0; 

    for (int step = 0; step < (size - 1); ++step) {
        int swapped = 0; 

        if (debugMode) {
            cout << "Pasada " << step + 1 << ":\n";
        }

        for (int i = 0; i < (size - step - 1); ++i) {
            if (debugMode) {
                cout << "  Comparando " << array[i] << " y " << array[i + 1];
            }

            if (array[i] > array[i + 1]) {
                if (debugMode) {
                    cout << " -> Intercambiando (porque " << array[i] << " > " << array[i + 1] << ")\n";
                }

                
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1; 
            } else if (debugMode) {
                cout << " -> No se intercambia (porque " << array[i] << " <= " << array[i + 1] << ")\n";
            }

            if (debugMode) {
                cout << "  Estado actual del arreglo:\n";
                printArray(array, size);
                cout << "  Presiona Enter para continuar...\n";
                cin.ignore(); 
            }
        }

        totalSteps++; 

        if (debugMode) {
            cout << "Estado del arreglo después de la pasada " << step + 1 << ":\n";
            printArray(array, size);
        }

       
        if (swapped == 0) {
            if (debugMode) {
                cout << "No hubo intercambios en este paso, el arreglo ya está ordenado.\n";
            }
            break;
        }

        if (debugMode) {
            cout << "Presiona Enter para avanzar al siguiente paso...";
            cin.ignore();
        }
    }

    return totalSteps; 
}

int callBubble() {
    while (true) { 
        int choice;
        int size = 0;
        int data[100]; 

        
        while (true) {
            cout << "Seleccione una opción:\n";
            cout << "1. Usar el arreglo por defecto\n";
            cout << "2. Ingresar el arreglo manualmente\n";
            cout << "3. Salir\n";
            cout << "Opción: ";
            cin >> choice;

            if (choice >= 1 && choice <= 3) {
                break; 
            } else {
                cout << "Opción no válida. Intenta de nuevo con una opción disponible.\n";
            }
        }

        if (choice == 3) { 
            cout << "Saliendo del programa...\n";
            break;
        }

        switch (choice) {
            case 1: {
               
                int defaultData[] = {-2, 45, 0, 11, -9};
                size = sizeof(defaultData) / sizeof(defaultData[0]);
                for (int i = 0; i < size; ++i) {
                    data[i] = defaultData[i];
                }
                break;
            }
            case 2: {
                
                cout << "Ingrese el número de elementos: ";
                cin >> size;
                cout << "Ingrese los elementos:\n";
                for (int i = 0; i < size; ++i) {
                    cin >> data[i];
                }
                break;
            }
        }

        int originalData[size];
        for (int i = 0; i < size; ++i) {
            originalData[i] = data[i];
        }

       
        auto start = high_resolution_clock::now();
        int totalStepsNormal = bubbleSort(data, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        
        cout << "Tiempo de ejecución: " << duration.count() << " microsegundos\n";
        cout << "Pasadas necesarias: " << totalStepsNormal << "\n";

        
        cout << "\nArreglo original:\n";
        printArray(originalData, size);

        cout << "Arreglo ordenado:\n";
        printArray(data, size);

       
        cout << "\nVamos a analizarlo. Presiona Enter para continuar...";
        cin.ignore(); 
        cin.ignore(); 

        
        int dataDebug[size];
        for (int i = 0; i < size; ++i) {
            dataDebug[i] = originalData[i];
        }

     
        cout << "Arreglo original:\n";
        printArray(dataDebug, size);
        int totalStepsDebug = bubbleSort(dataDebug, size, true);

        cout << "Arreglo ordenado en orden ascendente:\n";
        printArray(dataDebug, size);
        cout << "Pasadas necesarias: " << totalStepsDebug << "\n";

       
        cout << "\nOk, vamos a comprobar si está ordenado.\n";
        cout << "Presiona Enter para continuar...";
        cin.ignore(); 

       
        bubbleSort(dataDebug, size, true);

       
        int repeat;
        while (true) {
            cout << "\n¿Quiere ordenar otro arreglo? (1: Sí, 0: No): ";
            cin >> repeat;

            if (repeat == 0 || repeat == 1) {
                break; 
            } else {
                cout << "Opción no válida. Intenta de nuevo con una opción disponible.\n";
            }
        }

        if (repeat == 0) {
            break; 
        }
    }

    return 0;
}