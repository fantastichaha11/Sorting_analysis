#include "Function.h"

#include <chrono>
using namespace std::chrono;
typedef void(*pSort)(int*, int, long long&, double&, int);

pSort listSort[11] = { selectionSort, insertionSort, bubbleSort, shakerSort, shellSort, heapSort,
                        mergeSort, quickSort, countingSort, radixSort, flashSort };
string listNameSort[11] = { "Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort", "Heap Sort",
                            "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort" };
int listSize[6] = { 10000, 30000, 50000, 100000, 300000, 500000 };
string listData[4] = { "Random", "Sorted", "Reverse", "Nearly Sorted" };

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename)
{
    ofstream fp(filename, ios::app);

    int* a = NULL;

    GenerateData(a, n, typeData);
    pSort sort = listSort[typeSort];
    fp << listNameSort[typeSort] << ": " << n << ": " << listData[typeData] << endl;

    long long count_compare = 0;
    double time = 0;
    if (typeCount == COMPARE)
    {
        fp << "\tCompare: ";
        sort(a, n, count_compare, time, COMPARE);
        fp << count_compare << endl;
    }
    if (typeCount == TIME)
    {
        fp << "\tTime: ";
        auto start = high_resolution_clock::now();

        sort(a, n, count_compare, time, TIME);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        time = duration.count();
        fp << time << endl;
    }
    else 
    {
        int* b = new int[n];
        for (int i = 0; i < n; i++)
            b[i] = a[i];

        fp << "\tCompare: ";
        sort(a, n, count_compare, time, COMPARE);
        fp << count_compare << endl;

        fp << "\tTime: ";
        auto start = high_resolution_clock::now();

        sort(b, n, count_compare, time, TIME);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        time = duration.count();
        fp << time << endl;

        delete[]  b;
    }
    fp << endl;
    if (a != NULL)
        delete[] a;

    fp.close();
}

void output_an()
{
    for (int dataType = 0; dataType < 4; dataType++)
    {
        for (int size = 0; size < 6; size++)
        {
            for(int typeSort = 0; typeSort < 11; typeSort++)
            {
                if (dataType == RANDOM)
                {
                    outputSort(listSize[size], dataType, BOTH, typeSort, "An_Sorting.txt");
                }
                else
                {
                    outputSort(listSize[size], dataType, TIME, typeSort, "An_Sorting.txt");
                }
            }
        }
    }
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
