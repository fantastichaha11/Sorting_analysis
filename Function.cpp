#include "Function.h"

#include <chrono>
#include <sstream>
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
        auto duration = duration_cast<milliseconds>(stop - start);

        string timeUnit = "ms";
        time = (duration.count() * 1.0);
        /*if(duration.count() > 1000000)
        {
            time = (duration.count() * 1.0) / 1000000;
            timeUnit = "s";
        }*/
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
        sort(a, n, count_compare, time, TIME);
        fp << time << endl;

        delete[]  b;
    }
    fp << endl;
    if (a != NULL)
        delete[] a;

    fp.close();
}

void convertFile(string fileIn, string fileOut)
{
    ifstream fpIn(fileIn);
    ofstream fpOut(fileOut);

    string line;

    while (getline(fpIn, line))
    {
        size_t found = line.find("Time:");
        if (found != std::string::npos)
        {
            stringstream ss(line);

            string unit;
            double time;

            ss >> unit >> time;

            if (time > 1000000)
            {
                unit = "s";
                time = time / 1000000;
            }
            else
            {
				unit = "ms";
			}
            fpOut << "\tTime: ";
            fpOut << time << " " << unit << endl;
        }
        else
        {
			fpOut << line << endl;
		}
    }

    fpIn.close();
    fpOut.close();
}

void ouputRandom(string compareFile, string timeFile)
{
    ofstream fpCompare(compareFile, ios::trunc);
    ofstream fpTime(timeFile, ios::trunc);

    int* a = NULL;
    int* copy = NULL;

    for (int size = 0; size < 6; size++)
    {
        GenerateData(a, listSize[size], RANDOM);
        copy = new int[listSize[size]];

        fpCompare << listSize[size] << ": ";
        fpTime << listSize[size] << ": ";
        for (int typeSort = 0; typeSort < 11; typeSort++)
        {
            duplicateArr(a, copy, listSize[size]);

            long long count_compare = 0;
            double time = 0;
            pSort sort = listSort[typeSort];

            sort(copy, listSize[size], count_compare, time, COMPARE);
            fpCompare << count_compare << " ";

            duplicateArr(a, copy, listSize[size]);

            auto start = high_resolution_clock::now();
            sort(copy, listSize[size], count_compare, time, TIME);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            fpTime << duration.count() << " ";
        }
        if (copy != NULL)
            delete[] copy;
        fpCompare << endl;
        fpTime << endl;

    }

    fpCompare.close();
    fpTime.close();

    if (a != NULL)
		delete[] a;
}

void output_an()
{
    ouputRandom("Random_Compare.txt", "Random_Time.txt");

    ofstream fp;
    string filename;

    int* a = NULL;
    int* copy = NULL;

    for (int dataType = 1; dataType < 4; dataType++)
    {
        fp.open(listData[dataType] + "_Time.txt", ios::trunc);

        for (int size = 0; size < 6; size++)
        {
            GenerateData(a, listSize[size], RANDOM);
            copy = new int[listSize[size]];

            fp << listSize[size] << ": ";
            for (int typeSort = 0; typeSort < 11; typeSort++)
            {
                pSort sort = listSort[typeSort];
                long long count_compare = 0;
                double time = 0;
                duplicateArr(a, copy, listSize[size]);

                auto start = high_resolution_clock::now();
                sort(copy, listSize[size], count_compare, time, TIME);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                fp << duration.count() << " ";
            }
            if (copy != NULL)
                delete[] copy;
            fp << endl;
        }

        fp.close();
    }
    if (a != NULL)
    {
        delete[] a;
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
            fp << count_compare << " ";
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
