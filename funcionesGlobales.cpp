#include "funcionesGlobales.h"
#include "bubblesort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "bucketSort.h"
#include "heapSort.h"
#include "shellSort.h"
#include "linearSort.h"
#include "binarySort.h"
#include "countingSort.h"
#include "radixSort.h"

using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}


void menu(){
    int selecMenu;
    cout << "--- ADVERTENCIA!!!! \n";
    cout << "--- Si usted desea ingresar la Opción de array quemado del tipo \n";
    cout << "--- de impresión recuerde actualizar su array desde el codigo  \n";
    cout << "--- para poder imprimir lo deseado.\n";
	 cout <<"--- Menu de opciones ---\n";
	 cout <<"--- 1.  Bubble sort\n";
	 cout <<"--- 2.  Selection sort\n";
	 cout <<"--- 3.  Insertion sort\n";
	 cout <<"--- 4.  Merge sort\n";
	 cout <<"--- 5.  Quick sort\n";
	 cout <<"--- 6.  Counting sort\n";
	 cout <<"--- 7.  Radix sort\n";
	 cout <<"--- 8.  Buckect sort\n";
	 cout <<"--- 9.  Heap sort\n";
	 cout <<"--- 10. Shell sort\n";
	 cout <<"--- 11. linear sort\n";
	 cout <<"--- 12. binary sort \n";
	 cout <<"--- 13. salir \n";
	 cout <<"--- Ingrese una opcion: \n";
	 cin >> selecMenu;
	switch(selecMenu) {
	   case 1:
          callBubble();
		   break;
	   case 2:
	      selection_sort();
		   break;
	   case 3:
          callInsertion();
		   break;
	   case 4:
          callMerge();
		   break;
	   case 5:
	  	  callQuick();
		   break;
           case 6:
          callCounting();
		   break;
	   case 7:
          callRadix();
		   break;
	   case 8:
	   	  callBucket();
		   break;
	   case 9:
	   	  callHeap();
		   break;
	   case 10:
	      callShell();
		   break;
	   case 11:
	  	  linearCall();
		   break;
	   case 12:
	   	  callBinary();
		   break;
           case 13:
         cout << "saliendo del programa";
         break;
	   default:
		cout << "Error, la opcion no exite.\n";
		menu();
	}
}
