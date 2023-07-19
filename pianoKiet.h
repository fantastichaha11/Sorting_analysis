#include "DataGenerator.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

#define I_SORT 3
#define SAKER_SORT 4
//Insertion Sort
void insertionSort_countCompare(int* a, int n, int& count_compare);
void insertionSort_countTime(int* a, int n, int& count_compare);
void shakerSort_countTime(int* a, int n, int& count_compare);
