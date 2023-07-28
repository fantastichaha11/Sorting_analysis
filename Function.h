#pragma once
#include "sorting_functions.h"

#define A_MODE 0
#define C_MODE 1

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
void duplicateArr(int* src, int* des, int n);
void outputSort_kiet(int typeData, string filename);
void outputSort(int n, int typeData, int typeCount, int typeSort, string filename);
bool KeySearch(string key, string arr[], int n, short& code);
bool readInputFile(string fileName, int*& a, int& n);
void printResult(short orderCode, short outputCode, double time, long long count_compare);
void printCMD1(short algoCode, string fileName, short outputCode);
void printCMD2(short algoCode, int inputSize, short orderCode, short outputCode);
void printCMD3(short algoCode, int inputSize, short outputCode);
void Compare_mode(string var, string algo1, string algo2, string inputOrder[], int& n, int cmd);
void printCMD45(int* arr, int n, short algo1, short algo2);