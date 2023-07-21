#pragma once
#include "Function.h"
#include "anTroc.h"
#include "hieuHo.h"
#include "pianoKiet.h"
#include "sonOfABeach.h"
#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
using namespace std;

typedef void(*pSort)(int*, int, long long&, double&, int);

pSort listSort[11] = { selectionSort, insertionSort, bubbleSort, shakerSort, shellSort, heapSort,
						mergeSort, quickSort, countingSort, radixSort, flashSort };

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);