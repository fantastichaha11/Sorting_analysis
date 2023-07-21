#pragma once
#include "sorting_functions.h"

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
typedef void(*pSort)(int*, int, long long&, double&, int);
pSort listSort[11] = {selectionSort, insertionSort, bubbleSort, shakerSort, shellSort, heapSort,
						mergeSort, quickSort, countingSort, radixSort, flashSort };
void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
void duplicateArr(int* a, int* b, int n);
void outputSort_kiet(int typeData, string filename);
void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
void output_an();