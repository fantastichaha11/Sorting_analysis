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
        auto duration = duration_cast<microseconds>(stop - start);

        fp << duration.count() << endl;
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

void duplicateArr(int* src, int* des, int n) {
    for (int i = 0; i < n; i++) {
        des[i] = src[i];
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


//void printCMD4(int algo1, int algo2, string var1, int* arr, int n)
//{
//    cout << "Algorithm: " << listNameSort[algo1] << " | " << listNameSort[algo2] << endl;
//    cout << "Input file: " << var1 << endl;
//    cout << "Input size: " << n << endl;
//    cout << "---------------------------------" << endl;
//    double time1 = 0; double time2 = 0;
//    long long compare1 = 0; long long compare2 = 0;
//    pSort sort1 = listSort[algo1];
//    pSort sort2 = listSort[algo2];
//    sort1(arr, n, compare1, time1, COMPARE);
//    sort1(arr, n, compare1, time1, TIME);
//    //-------------------------------------------------------------------
//    sort2(arr, n, compare2, time2, COMPARE);
//    sort2(arr, n, compare2, time2, TIME);
//
//    cout << "Running time: " << time1 << " | " << time2 << endl;
//    cout << "Comparisons: " << compare1 << " | " << compare2 << endl;
//    return;
//}
//
//void printCMD5(int algo1, int algo2, string var2, int* arr, int n)
//{
//    cout << "Algorithm: " << listNameSort[algo1] << " | " << listNameSort[algo2] << endl;
//    cout << "Input size: " << n << endl;
//    cout << "Input size: " << stoi(var2) << endl;
//    cout << "---------------------------------" << endl;
//    double time1 = 0; double time2 = 0;
//    long long compare1 = 0; long long compare2 = 0;
//    pSort sort1 = listSort[algo1];
//    pSort sort2 = listSort[algo2];
//    sort1(arr, n, compare1, time1, COMPARE);
//    sort1(arr, n, compare1, time1, TIME);
//    //-------------------------------------------------------------------
//    sort2(arr, n, compare2, time2, COMPARE);
//    sort2(arr, n, compare2, time2, TIME);
//
//    cout << "Running time: " << time1 << " | " << time2 << endl;
//    cout << "Comparisons: " << compare1 << " | " << compare2 << endl;
//    return;
//}

bool KeySearch(string key, string arr[], int n, short& code)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            code = i;
            return true;
        }
    }
    return false;
}

bool readInputFile(string fileName, int*& a, int& n)
{
    ifstream fp(fileName);

    if (!fp.is_open())
    {
		cout << "Can't open file " << fileName << endl;
		return false;
	}

    fp >> n;
    if (a != NULL)
    {
        delete[] a;
    }
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        fp >> a[i];
    }
    fp.close();

    return true;
}

void printResult(short orderCode, short outputCode, double time, long long count_compare)
{
    cout << "Input order: " << listData[orderCode] << endl;
    cout << "---------------------------------\n";
    if (outputCode == TIME || outputCode == BOTH)
    {
        cout << "Running time: " << time << endl;
    }
    if (outputCode == COMPARE || outputCode == BOTH)
    {
        cout << "Comparisons: " << count_compare << endl;
    }
}

void printCMD1(short algoCode, string fileName, short outputCode)
{
    int* a = NULL;
    int n;
    double time = 0;
    long long count_compare = 0;
    pSort sort = listSort[algoCode];
    
    if (readInputFile(fileName, a, n) == 0)
    {
        return;
    }

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << listNameSort[algoCode] << endl;
    cout << "Input file: " << fileName << endl;
    cout << "Input size: " << n << endl;
    cout << "---------------------------------\n";

    int* copy = new int[n];
    if (outputCode == TIME || outputCode == BOTH)
    {
        duplicateArr(a, copy, n);

        auto start = high_resolution_clock::now();
        sort(copy, n, count_compare, time, TIME);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Running time: " << duration.count() << " microseconds" << endl;
    }
    if (outputCode == COMPARE || outputCode == BOTH)
    {
        duplicateArr(a, copy, n);

        sort(copy, n, count_compare, time, COMPARE);
        cout << "Comparisons: " << count_compare << endl;
    }

    ofstream fp("output.txt");

	fp << n << endl;
    for (int i = 0; i < n; i++)
    {
		fp << copy[i] << " ";
	}
	fp.close();

    delete[] copy;
}

void printCMD2(short algoCode, int inputSize, short orderCode, short outputCode)
{
    int* a = NULL;
    int n = inputSize;
    double time = 0;
    long long count_compare = 0;
    pSort sort = listSort[algoCode];
    GenerateData(a, n, orderCode);
    sort(a, n, count_compare, time, outputCode);
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << listNameSort[algoCode] << endl;
    cout << "Input size: " << n << endl;
    printResult(orderCode, outputCode, time, count_compare);
}

void printCMD3(short algoCode, int inputSize, short outputCode)
{
    pSort sort = listSort[algoCode];
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << listNameSort[algoCode] << endl;
    cout << "Input size: " << inputSize << endl;
    for (int i = 0; i < 4; i++)
    {
        int* a = NULL;
        int n = inputSize;
        double time = 0;
        long long count_compare = 0;
        GenerateData(a, n, i);
        sort(a, n, count_compare, time, outputCode);
        printResult(i, outputCode, time, count_compare);
        cout << endl;
    }
}

void Compare_mode(string var1, string var2, string algo1, string algo2, string inputOrder[], int& n, int cmd) {
    short first_algo = -1;
    short second_algo = -1;
    KeySearch(algo1, listNameSort, 11, first_algo);
    KeySearch(algo2, listNameSort, 11, second_algo);
    if (first_algo == -1 || second_algo == -1) {
        cout << "Invalid algorithms";
        return;
    }
    int* arr = NULL;
    if (cmd == 4) {
        int a;
        n = 0;
        ifstream read;
        read.open(var1, ios::in);
        if (read.fail()) {
            cout << "Can not read " << var1 << endl;
            return;
        }
        while (read >> a) n++;
        read.seekg(0, ios::beg);
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            read >> arr[i];
        }
        read.close();
        cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
        cout << "Input file: " << var1 << endl;
        cout << "Input size: " << n << endl;
        cout << "---------------------------------" << endl;
    }
    else if (cmd == 5) {
        //KeySearch for the order of sort
        short order = -1;
        KeySearch(var2, inputOrder, 4, order);
        if (order == -1) {
            cout << "Invalid input order";
            return;
        }
        arr = new int[n];
        GenerateData(arr, n, order);
        cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
        cout << "Input size: " << n << endl;
        cout << "Input order: " << var2 << endl;
        cout << "---------------------------------" << endl;
    }
    printCMD45(arr, n, first_algo, second_algo);
}

void printCMD45(int* arr, int n, short algo1, short algo2)
{
    int* copy = new int[n];
    long long compare1 = 0; long long compare2 = 0;
    double time1 = 0; double time2 = 0;
    pSort sort1 = listSort[algo1];
    pSort sort2 = listSort[algo2];
    duplicateArr(arr, copy, n);

    //Calculate comparisons of the first sort algorithm
    sort1(copy, n, compare1, time1, COMPARE);

    //Calculate time of the first sort algorithm
    duplicateArr(arr, copy, n);
    auto start1 = high_resolution_clock::now();
    sort1(copy, n, compare1, time1, TIME);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    //Calculate comparisons of the second sort algorithm
    duplicateArr(arr, copy,n);
    sort2(copy, n, compare2, time2, COMPARE);

    //Calculate time of the second sort algorithm
    duplicateArr(arr, copy, n);
    auto start2 = high_resolution_clock::now();
    sort2(copy, n, compare2, time2, TIME);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    //Print ouput
    cout << "Running time: " << duration1.count() << " | " << duration2.count() << " (in microseconds)" << endl;
    cout << "Comparisons : " << compare1 << " | " << compare2 << endl;
    return;
}