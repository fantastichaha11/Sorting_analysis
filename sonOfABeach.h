#pragma once
#include<string>
using namespace std;

#define S_SORT 0
#define SS_SORT 4
#define C_SORT 8

void selectionSort_countCompare(int* a, int n, long long& count_compare);
void selectionSort_countTime(int* a, int n, double& time);
void countingSort_countCompare(int* a, int n, int k, long long& count_compare);
void countingSort_countTime(int* a, int n, int k, double& time);
void shellSort_countCompare(int* a, int n, long long& count_compare);
void shellSort_countTime(int* a, int n, double& time);