#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
using namespace std;

#define S_SORT 0
#define I_SORT 1
#define B_SORT 2
#define SHAKER_SORT 3
#define SS_SORT 4
#define H_SORT 5
#define M_SORT 6
#define Q_SORT 7
#define C_SORT 8
#define R_SORT 9
#define F_SORT 10

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
void selectionSort_countCompare(int* a, int n, long long& count_compare);
void selectionSort_countTime(int* a, int n, double& time);
void countingSort_countCompare(int* a, int n, long long& count_compare);
void countingSort_countTime(int* a, int n, double& time);
void shellSort_countCompare(int* a, int n, long long& count_compare);
void shellSort_countTime(int* a, int n, double& time);
void selectionSort(int* a, int n, long long& count_compare, double& time, int typeCount);
void countingSort(int* a, int n, long long& count_compare, double& time, int typeCount);
void shellSort(int* a, int n, long long& count_compare, double& time, int typeCount);
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
//Hieu
void insertionSort(int a[], int n);
void flashSort_time(int a[], int n, double& time);
void insertionSort_compare(int a[], int n, long long& count_compare);
void flashSort_compare(int a[], int n, long long& count_compare);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSort_time(int arr[], int n, double& time);
int getMax_compare(int arr[], int n, long long& count_compare);
void countSort_compare(int arr[], int n, int exp, long long& count_compare);
void radixSort_compare(int arr[], int n, long long& count_compare);
void flashSort(int* a, int n, long long& count_compare, double& time, int typeCount);
void radixSort(int* a, int n, long long& count_compare, double& time, int typeCount);

