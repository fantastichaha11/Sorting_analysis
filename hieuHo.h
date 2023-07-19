#pragma once

#define A_MODE 0
#define C_MODE 1

#include <string>
using namespace std;





bool KeySearch(string key, string arr[], int n, short& code);

void insertionSort(int a[], int n);
void flashSort_time(int a[], int n, double& time);
void insertionSort_compare(int a[], int n, int& countCmp);
void flashSort_compare(int a[], int n, int& countCmp);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSort_time(int arr[], int n, int& time);
int getMax_compare(int arr[], int n, int& countCmp);
void countSort_compare(int arr[], int n, int exp, int& countCmp);
void radixSort_compare(int arr[], int n, int& countCmp);