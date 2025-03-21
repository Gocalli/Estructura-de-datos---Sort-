#include "selectionSort.h"
#include "funcionesGlobales.h"

using namespace std;
using namespace std::chrono;

void swap(int *a, int *b);
void selection_sort();
void selectionSort(int array[], int size);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size){
   for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
   for (int i = step + 1; i < size; i++) {


      if (array[i] < array[min_idx])
        min_idx = i;
   }

    swap(&array[min_idx], &array[step]);
  }
}

void selection_sort(){
   cout << "--- ingrese opcion 1 para Array quemado.\n";
   cout << "--- ingrese opcion 2 para Array teclado.\n";
   cout << "--- ingrese opcion 3 para Array texto.\n";
   int mode;
   cin >>mode;
   if (mode==1){
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    cout << "--- El Array original fue: \n";   
    printArray(data, size);
    cout << "--- El ordenamiento que se realiza es:\n";

    auto start = high_resolution_clock::now();
    selectionSort(data, size);
    cout << "--- El Array ordenado es:\n";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    printArray(data, size);

    cout << "--- El tiempo que demoro hacer el proceso es: "<< duration.count() << " microseconds" << endl;
   }
      else{
   if(mode==2){
    cout << "--- Bienvenido en esta opción llenamos el array por teclado.\n";
    int size;

    cout << "--- Ingrese el tamaño del Array:\n";
    cin >> size;

    int data[size];

    cout << "--- Ingrese los números del array:\n";
   for (int i = 0; i < size; i++) {
    cin >> data[i];
   }
    cout << "--- El Array original fue: \n";   
    printArray(data, size);
    cout << "--- El ordenamiento que se realiza es:\n";

    auto start = high_resolution_clock::now();
    selectionSort(data, size);
    cout << "--- El Array ordenado es:\n";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    printArray(data, size);

    cout << "--- El tiempo que demoro hacer el proceso es: "<< duration.count() << " microseconds" << endl;
   }
      else{
   if(mode==3){
    cout << "--- Bienvenido en esta opción llenamos el array por documento.\n";

    ifstream inputFile("array.txt");

     if (!inputFile.is_open()) {
    cout << "--- Error: No se pudo abrir el archivo.\n"<< endl;

    ;
     }
    int size;

    inputFile >> size;

    int data[size];

     for (int i = 0; i < size; i++) {
    inputFile >> data[i];
     }

    inputFile.close();
    cout << "--- El Array original fue: \n";   
    printArray(data, size);
    cout << "--- El ordenamiento que se realiza es:\n";

    auto start = high_resolution_clock::now();
    selectionSort(data, size);
    cout << "--- El Array ordenado es:\n";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    printArray(data, size);

    cout << "--- El tiempo que demoro hacer el proceso es: "<< duration.count() << " microseconds" << endl;
    }
      else{
    cout << "--- fuera de rango.\n";
    selection_sort();
         }
      }
      }
}
