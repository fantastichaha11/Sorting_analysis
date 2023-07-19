#include "sonOfABeach.h"
#include "DataGenerator.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

//Selection sort
void selectionSort_countCompare(int* a, int n, int& count_compare)
{
	count_compare = 0;
	for (int i = 0; ++count_compare && i < n - 1; i++)
	{
		int minID = i;
		for (int j = i + 1; ++count_compare && j < n; j++)
		{
			if (++count_compare && a[minID] > a[j]) minID = j;
		}
		swap(a[i], a[minID]);
	}
}


void selectionSort_countTime(int* a, int n, double& time)
{
	clock_t start, end;
	start = clock();

	for (int i = 0; i < n - 1; i++)
	{
		int minID = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[minID] > a[j]) minID = j;
		}
		swap(a[i], a[minID]);
	}

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//Counting sort
void countingSort_countCompare(int* a, int n, int k, int& count_compare)
{
	count_compare = 0;
	for (int i = 0; ++count_compare && i < n; i++)
	{
		if (++count_compare && a[i] > k) k = a[i];
	}

	int* S = new int[n];
	int* C = new int[k + 1];

	for (int j = 0; ++count_compare && j <= k; j++)
	{
		C[j] = 0;
	}

	for (int i = 0; ++count_compare && i < n; i++)
	{
		C[a[i]] = C[a[i]] + 1;
	}

	for (int i = 1; ++count_compare && i <= k; i++)
	{
		C[i] = C[i - 1] + C[i];
	}

	for (int i = n - 1; ++count_compare && i >= 0; i--)
	{
		S[C[a[i]] - 1] = a[i];
		C[a[i]] = C[a[i]] - 1;
	}
	delete[]C;
	return;
}

void countingSort_countTime(int* a, int n, int k, double& time)
{
	clock_t start, end;
	start = clock();

	for (int i = 0; i < n; i++)
	{
		if (a[i] > k) k = a[i];
	}

	int* S = new int[n];
	int* C = new int[k + 1];

	for (int j = 0; j <= k; j++)
	{
		C[j] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		C[a[i]] = C[a[i]] + 1;
	}

	for (int i = 1; i <= k; i++)
	{
		C[i] = C[i - 1] + C[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		S[C[a[i]] - 1] = a[i];
		C[a[i]] = C[a[i]] - 1;
	}

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	delete[]C;
	return;
}

//Shell sort
void shellSort_countCompare(int* a, int n, int& count_compare)
{
	count_compare = 0;
	for (int gap = n / 2; ++count_compare && gap > 0; gap /= 2)
	{
		for (int i = gap; ++count_compare && i < n; i++)
		{
			int temp = a[i];
			int j;
			for (j = i; (++count_compare && j >= gap) && (++count_compare && a[j - gap] > temp); j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

void shellSort_countTime(int* a, int n, double& time)
{
	clock_t start, end;
	start = clock();

	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//Write file
