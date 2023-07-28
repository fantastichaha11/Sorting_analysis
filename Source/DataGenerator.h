#pragma once
template <class T>
void HoanVi(T& a, T& b);

#define RANDOM 0
#define SORTED 1
#define REVERSE 2
#define N_SORTED 3

#define COMPARE 0
#define TIME 1
#define BOTH 2

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int*& a, int n, int dataType);