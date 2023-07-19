#include "pianoKiet.h"
using namespace std;

//Bubble Sort
void insertionSort_countCompare(int* a, int n, long long& count_compare) {
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
void insertionSort_countTime(int* a, int n, double& time) {
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
void shakerSort_countCompare(int* a, int n, int& count_compare) { //Ref: geeksforgeeks
    count_compare = 0;
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;
        // loop from left to right same as the bubble sort
        for (int i = start; ++count_compare && i < end; i++) {
            if (++count_compare && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // if nothing moved, then array is sorted. otherwise, reset the swapped flag so that it can be used in the next stage
        if (!swapped)
            break;
        // move the end point back by one, because item at the end is in its rightful spot
        end--;
        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; ++count_compare && i >= start; i--) {
            if (++count_compare && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // increase the starting point, because the last stage would have moved the next smallest number to its rightful spot.
        ++start;
    }
}
void shakerSort_countTime(int* a, int n, double &time) { //Ref: geeksforgeeks
    clock_t begin, finish;
    begin = clock();
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;
        // loop from left to right same as the bubble sort
        for (int i = start; i < end; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // if nothing moved, then array is sorted. otherwise, reset the swapped flag so that it can be used in the next stage
        if (!swapped)
            break;
        // move the end point back by one, because item at the end is in its rightful spot
        end--;
        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; i--) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // increase the starting point, because the last stage would have moved the next smallest number to its rightful spot.
        ++start;
    }
    finish = clock();
    time = (double)(begin - finish) / CLOCKS_PER_SEC;
}
