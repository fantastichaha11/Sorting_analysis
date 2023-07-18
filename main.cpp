#include "anTroc.h"
#include "hieuHo.h"
#include "pianoKiet.h"
#include "sonOfABeach.h"
#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

int main()
{
	int* a = NULL;
	int n = 10000;

	GenerateData(a, n, 1);

	double time;
	quickSort_countTime(a, n, time);
	cout << "Sort: " << time << endl;
	system("pause");
	return 0;
}