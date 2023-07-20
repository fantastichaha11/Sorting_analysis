#include "DataGenerator.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

#define I_SORT 3
#define SHAKER_SORT 4
#define M_SORT 7
//Insertion Sort
void insertionSort(int* a, int n, long long& count_compare, double& time, int typeCount);
void insertionSort_countCompare(int* a, int n, long long& count_compare);
void insertionSort_countTime(int* a, int n, double& time);
void shakerSort(int* a, int n, long long& count_compare, double& time, int typeCount);
void shakerSort_countTime(int* a, int n, double& time);
void shakerSort_countCompare(int* a, int n, long long& count_compare);
void mergeSort(int* a, int n, long long& count_compare, double& time, int typeCount);
void merge_countCompare(int* a, int first, int mid, int last, long long& count_compare);
void mergeSort_countCompare(int* a, int first, int last, long long& count_compare);
void merge_countTime(int* a, int first, int mid, int last);
void mergeSort_countTime(int* a, int first, int last);


