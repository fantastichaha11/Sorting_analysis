#include "anTroc.h"
#include <iostream>
#include <time.h>
using namespace std;

//Bubble Sort
void bubbleSort_countCompare(int* a, int n, int& count_compare)
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

//Heap sort
void heapify_compare(int* a, int i, int n, int& count_compare)
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
void heapSort_countCompare(int* a, int n, int& count_compare)
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

//Quick sort
int partition_compare(int arr[], int l, int r, int& count_compare)
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
void quickSort_compare(int* a, int l, int r, int& count_compare)
{
    if (++count_compare && l >= r)
        return;

    int p = partition_compare(a, l, r, count_compare);
    quickSort_compare(a, l, p - 1, count_compare);
    quickSort_compare(a, p + 1, r, count_compare);
}
void quickSort_countCompare(int* a, int n, int& count_compare)
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
    if (l >= r)
        return;

    int p = partition_time(a, l, r);
    quickSort_time(a, l, p - 1);
    quickSort_time(a, p + 1, r);
}
void quickSort_countTime(int* a, int n, double& time)
{
    clock_t start, end;
    start = clock();
    quickSort_time(a, 0, n - 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
