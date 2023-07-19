#include "pianoKiet.h"
#include "DataGenerator.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

//Bubble Sort
void insertionSort_countCompare(int* a, int n, int& count_compare) {
	count_compare = 0;
	for (int i = 1; ++count_compare && i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (++count_compare && j >= 0 && ++count_compare && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void insertionSort_countCompare(int* a, int n, double& time) {
	clock_t start, end;
	start = clock();
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}