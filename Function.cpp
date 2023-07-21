#include "Function.h"

void outputSort(int n, int typeData, int typeCount, int typeSort, string filename)
{
    ofstream fp(filename, ios::app);

    int* a = NULL;

    pSort sort = listSort[typeSort];

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