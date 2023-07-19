#pragma once

#define A_MODE 0
#define C_MODE 1

#include <string>
using namespace std;





bool KeySearch(string key, string arr[], int n, short& code);


#define R_SORT 9
#define F_SORT 10

void insertionSort(int a[], int n);
void flashSort_time(int a[], int n, double& time);
void insertionSort_compare(int a[], int n, int& countCmp);
void flashSort_compare(int a[], int n, int& countCmp);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSort_time(int arr[], int n, double& time);
int getMax_compare(int arr[], int n, long long& count_compare);
void countSort_compare(int arr[], int n, int exp, long long& count_compare);
void radixSort_compare(int arr[], int n, long long& count_compare);

void flashSort(int* a, int n, long long& count_compare, double& time, int typeCount);
void radixSort(int* a, int n, long long& count_compare, double& time, int typeCount);