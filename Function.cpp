#include "Function.h"

typedef void(*pSort)(int*, int, long long&, double&, int);

pSort listSort[11] = { selectionSort, insertionSort, bubbleSort, shakerSort, shellSort, heapSort,
                        mergeSort, quickSort, countingSort, radixSort, flashSort };
string listNameSort[11] = { "Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort", "Heap Sort",
                            "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort" };

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename)
{
    ofstream fp(filename, ios::app);

    int* a = NULL;

    pSort sort = listSort[typeSort];
    fp << listNameSort[typeSort] << endl;

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
void duplicateArr(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}
void outputSort_kiet(int typeData, string filename) {
    ofstream fp(filename, ios::trunc);
    int n[] = { 10000, 30000, 50000, 100000, 300000, 500000 };
    int* a = NULL;
    pSort sort;
    long long count_compare = 0;
    int* copy = NULL;
    double time;
    for (int i = 0; i < 6; i++) {
        GenerateData(a, n[i], typeData);
        copy = new int[n[i]];
        fp << n[i] << ": ";
        for (int j = 0; j < 11; j++) {
            duplicateArr(a, copy, n[i]);
            sort = listSort[j];
            sort(copy, n[i], count_compare, time, COMPARE);
            fp << count_compare << "/";
            duplicateArr(a, copy, n[i]);
            sort(copy, n[i], count_compare, time, TIME);
            fp << time << " ";
        }
        delete[] copy;
        copy = NULL;
        fp << endl;
    }
    if (a != NULL)
        delete[] a;
    if (copy != NULL)
        delete[] copy;
    fp.close();
}
