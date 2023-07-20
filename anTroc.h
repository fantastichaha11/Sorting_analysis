#pragma once
#include <string>
#include "pianoKiet.h"
using namespace std;

#define B_SORT 2
#define H_SORT 5
#define Q_SORT 7

//Bubble sort
void bubbleSort_countCompare(int* a, int n, long long& count_compare);
void bubbleSort_countTime(int* a, int n, double& time);
void bubbleSort(int* a, int n, long long& count_compare, double& time, int typeCount);

//Heap sort
void heapify_compare(int* a, int i, int n, long long& count_compare);
void heapSort_countCompare(int* a, int n, long long& count_compare);

void heapify_time(int* a, int i, int n);
void heapSort_countTime(int* a, int n, double& time);

void heapSort(int* a, int n, long long& count_compare, double& time, int typeCount);

//Quick sort
int partition_compare(int arr[], int l, int r, long long& count_compare);
void quickSort_compare(int* a, int l, int r, long long& count_compare);
void quickSort_countCompare(int* a, int n, long long& count_compare);

int partition_time(int arr[], int l, int r);
void quickSort_time(int* a, int l, int r);
void quickSort_countTime(int* a, int n, double& time);

void quickSort(int* a, int n, long long& count_compare, double& time, int typeCount);

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);