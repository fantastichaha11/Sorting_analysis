#include "pianoKiet.h"
using namespace std;

//Bubble Sort
void insertionSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
        insertionSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        insertionSort_countTime(a, n, time);
}
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
void shakerSort(int* a, int n, long long& count_compare, double& time, int typeCount) {
    time = 0;
    count_compare = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
        shakerSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        shakerSort_countTime(a, n, time);
}
void shakerSort_countCompare(int* a, int n, long long& count_compare) { //Ref: geeksforgeeks
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
        swapped = false;
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
    time = (double)(finish - begin) / CLOCKS_PER_SEC;
}
void mergeSort(int* a, int n, long long& count_compare, double& time, int typeCount) {
    time = 0;
    count_compare = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
        mergeSort_countCompare(a, 0, n - 1, count_compare);
    if (typeCount == TIME || typeCount == BOTH) {
        clock_t start, end;
        start = clock();
        mergeSort_countTime(a, 0, n - 1);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
    }
}
void merge_countCompare(int *a, int first, int mid, int last, long long & count_compare) {
    int* temp = new int[last + 1];
    int f1 = first, l1 = mid;
    int f2 = mid + 1, l2 = last;
    int i = first;
    while (count_compare+=2 && (f1 <= l1) && (f2 <= l2)) {
        if (count_compare += 2 && a[f1] <= a[f2]) {
            temp[i] = a[f1];
            f1++;
        }
        else {
            temp[i] = a[f2];
            f2++;
        }
        i++;
    }
    while (count_compare += 2 && f1 <= l1) {
        temp[i] = a[f1];
        i++;
        f1++;
    }
    while (count_compare += 2 && f2 <= l2) {
        temp[i] = a[f2];
        f2++;
        i++;
    }
    for (i = first; count_compare += 2 && i <= last; i++) {
        a[i] = temp[i];
    }
    delete[] temp;
}
void mergeSort_countCompare(int *a, int first, int last, long long& count_compare) {
    if (count_compare += 2 && first >= last) {
        return;
    }
    int mid = (first + last) / 2;
    mergeSort_countCompare(a, first, mid, count_compare);
    mergeSort_countCompare(a, mid + 1, last, count_compare);
    merge_countCompare(a, first, mid, last, count_compare);
}
void merge_countTime(int* a, int first, int mid, int last) {
    int* temp = new int[last + 1];
    int f1 = first, l1 = mid;
    int f2 = mid + 1, l2 = last;
    int i = first;
    while ((f1 <= l1) && (f2 <= l2)) {
        if (a[f1] <= a[f2]) {
            temp[i] = a[f1];
            f1++;
        }
        else {
            temp[i] = a[f2];
            f2++;
        }
        i++;
    }
    while (f1 <= l1) {
        temp[i] = a[f1];
        i++;
        f1++;
    }
    while (f2 <= l2) {
        temp[i] = a[f2];
        f2++;
        i++;
    }
    for (i = first; i <= last; i++) {
        a[i] = temp[i];
    }
    delete[] temp;
}
void mergeSort_countTime(int* a, int first, int last) {
    if (first >= last) {
        return;
    }
    int mid = (first + last) / 2;
    mergeSort_countTime(a, first, mid);
    mergeSort_countTime(a, mid + 1, last);
    merge_countTime(a, first, mid, last);
}


