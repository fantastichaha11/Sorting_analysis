#include "Function.h"
#include "anTroc.h"
#include "hieuHo.h"
#include "pianoKiet.h"
#include "sonOfABeach.h"
#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename)
{
    ofstream fp(filename, ios::app);

    int* a = NULL;

    void (*sort) (int*, int, long long&, double&, int) = NULL;

    if (typeSort == B_SORT)
    {
        sort = bubbleSort;
        fp << "Bubble Sort: " << endl;
    }
    else if (typeSort == H_SORT)
    {
        sort = heapSort;
        fp << "Heap Sort: " << endl;
    }
    else if (typeSort == Q_SORT)
    {
        sort = quickSort;
        fp << "Quick Sort: " << endl;
    }
    else if (typeSort == M_SORT) {
        sort = mergeSort;
        fp << "Merge Sort: " << endl;
    }
    else if (typeSort == I_SORT) {
        sort = insertionSort;
        fp << "Insertion Sort: " << endl;
    }
    else if (typeSort == SHAKER_SORT) {
        sort = shakerSort;
        fp << "Shaker Sort: " << endl;
    }
    long long count_compare = 0;
    double time = 0;
    if (typeCount == COMPARE)
    {
        fp << "\tCompare: ";
        GenerateData(a, n, typeData);
        sort(a, n, count_compare, time, COMPARE);
        fp << count_compare << endl;
    }
    if (typeCount == TIME)
    {
        fp << "\tTime: ";
        GenerateData(a, n, typeData);
        sort(a, n, count_compare, time, TIME);
        fp << time << endl;
    }
    else {
        GenerateData(a, n, typeData);

        int* b = new int[n];
        for (int i = 0; i < n; i++)
            b[i] = a[i];

        fp << "\tCompare: ";
        sort(a, n, count_compare, time, COMPARE);
        fp << count_compare << endl;

        fp << "\tTime: ";
        sort(b, n, count_compare, time, TIME);
        fp << time << endl;

        delete[]  b;
    }

    if (a != NULL)
        delete[] a;

    fp.close();
}