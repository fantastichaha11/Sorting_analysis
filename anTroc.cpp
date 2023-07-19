#include "anTroc.h"
#include "DataGenerator.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

//Bubble Sort
void bubbleSort_countCompare(int* a, int n, long long& count_compare)
{
    count_compare = 0;

    int i, j;
    bool swapped;
    for (i = 0; ++count_compare && i < n - 1; i++) {
        swapped = false;
        for (j = 0; ++count_compare && j < n - i - 1; j++) {
            if (++count_compare && a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (++count_compare && swapped == false)
            break;
    }
}

void bubbleSort_countTime(int* a, int n, double& time)
{
    clock_t start, end;

    start = clock();
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void bubbleSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if (typeCount == COMPARE || typeCount == BOTH)
        bubbleSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        bubbleSort_countTime(a, n, time);
}

//Heap sort
void heapify_compare(int* a, int i, int n, long long& count_compare)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;

    if ((++count_compare && l < n) && (++count_compare && a[l] > a[max]))
        max = l;

    if ((++count_compare && r < n) && (++count_compare && a[r] > a[max]))
        max = r;

    if (++count_compare && max != i)
    {
        swap(a[i], a[max]);
        heapify_compare(a, max, n, count_compare);
    }
}
void heapSort_countCompare(int* a, int n, long long& count_compare)
{
    count_compare = 0;
    for (int i = n / 2; ++count_compare && i >= 0; i--)
        heapify_compare(a, i, n, count_compare);

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify_compare(a, 0, i, count_compare);
    }
}

void heapify_time(int* a, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;

    if (l < n && a[l] > a[max])
        max = l;

    if (r < n && a[r] > a[max])
        max = r;

    if (max != i)
    {
        swap(a[i], a[max]);
        heapify_time(a, max, n);
    }
}
void heapSort_countTime(int* a, int n, double& time)
{
    clock_t start, end;

    start = clock();
    for (int i = n / 2; i >= 0; i--)
        heapify_time(a, i, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify_time(a, 0, i);
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void heapSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if (typeCount == COMPARE || typeCount == BOTH)
        heapSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        heapSort_countTime(a, n, time);
}

//Quick sort
int partition_compare(int arr[], int l, int r, long long& count_compare)
{
    // Choosing the pivot
    int pivot = arr[r];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (l - 1);

    for (int j = l; ++count_compare && j <= r - 1; j++) {

        // If current element is smaller than the pivot
        if (++count_compare && arr[j] < pivot) {

            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}
void quickSort_compare(int* a, int l, int r, long long& count_compare)
{
    // Create an auxiliary stack
    int* stack = new int[r - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = r;

    // Keep popping from stack while is not empty
    while (++ count_compare && top >= 0) {
        // Pop h and l
        r = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition_time(a, l, r);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (++count_compare && p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (++count_compare && p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
    delete[] stack;
}
void quickSort_countCompare(int* a, int n, long long& count_compare)
{
    count_compare = 0;

    quickSort_compare(a, 0, n - 1, count_compare);
}

int partition_time(int arr[], int l, int r)
{
    int pivot = arr[r];

    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {

        if (arr[j] < pivot) {

            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quickSort_time(int* a, int l, int r)
{
    int* stack = new int[r - l + 1];

    int top = -1;

    stack[++top] = l;
    stack[++top] = r;

    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];
        
        int p = partition_time(a, l, r);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
    delete[] stack;
}
void quickSort_countTime(int* a, int n, double& time)
{
    clock_t start, end;
    start = clock();
    quickSort_time(a, 0, n - 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void quickSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if(typeCount == COMPARE || typeCount == BOTH)
		quickSort_countCompare(a, n, count_compare);
	if(typeCount == TIME || typeCount == BOTH)
		quickSort_countTime(a, n, time);
}

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename)
{
    ofstream fp(filename, ios::app);

    int* a = NULL;

    void (*sort) (int*, int, long long&, double&, int) = NULL;

    if(typeSort == B_SORT)
    {
        sort = bubbleSort;
        fp << "Bubble Sort: " << endl;
    }
	else if(typeSort == H_SORT)
    {
        sort = heapSort;
        fp << "Heap Sort: " << endl;
    }
	else if(typeSort == Q_SORT)
    {
        sort = quickSort;
        fp << "Quick Sort: " << endl;
    }

    int count_compare = 0;
    double time = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
    {
        fp << "\tCompare: ";
        GenerateData(a, n, typeData);
        sort(a, n, count_compare, time, COMPARE);
        fp << count_compare << endl;
    }
    if (typeCount == TIME || typeCount == BOTH)
    {
        fp << "\tTime: ";
        GenerateData(a, n, typeData);
        sort(a, n, count_compare, time, TIME);
        fp << time << endl;
    }

    if(a != NULL)
        delete[] a;

    fp.close();
}