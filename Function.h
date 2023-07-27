#pragma once
#include "sorting_functions.h"

#define A_MODE 0
#define C_MODE 1

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
void duplicateArr(int* a, int* b, int n);
void outputSort_kiet(int typeData, string filename);
void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
void printCMD4(int algo1, int algo2, string var1, int* arr, int n);
void printCMD5(int algo1, int algo2, string var2, int* arr, int n);
void output_an();

bool KeySearch(string key, string arr[], int n, short& code);
void readInputFile(string fileName, int*& a, int& n);
void printResult(short orderCode, short outputCode, double time, long long count_compare);
void printCMD1(short algoCode, string fileName, short outputCode);
void printCMD2(short algoCode, int inputSize, short orderCode, short outputCode);
void printCMD3(short algoCode, int inputSize, short outputCode);
