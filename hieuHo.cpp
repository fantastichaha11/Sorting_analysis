#include "hieuHo.h"
#include "DataGenerator.h"
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;


void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void flashSort_time(int a[], int n, double& time)
{
	clock_t start, end;

	start = clock();

	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

void insertionSort_compare(int a[], int n, int& countCmp)
{
	for (int i = 1; ++countCmp && i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (++countCmp && j >= 0 && ++countCmp && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void flashSort_compare(int a[], int n, int& countCmp)
{
	countCmp = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++countCmp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++countCmp && i < n; i++)
	{
		if (++countCmp && a[i] < minVal)
			minVal = a[i];
		if (++countCmp && a[i] > a[max])
			max = i;
	}
	if (++countCmp && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++countCmp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++countCmp && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++countCmp && nmove < n - 1)
	{
		while (++countCmp && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++countCmp && k < 0) break;
		while (++countCmp && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort_compare(a, n, countCmp);
}

// A utility function to get maximum
// value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(int arr[], int n, int exp)
{

	// Output array
	int* output = new int[n];
	int i, count[10] = { 0 };

	// Store count of occurrences
	// in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i]
	// now contains actual position
	// of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[],
	// so that arr[] now contains sorted
	// numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	delete[] output;
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixSort_time(int arr[], int n, int& time)
{
	clock_t start, end;

	start = clock();

	// Find the maximum number to
	// know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit.
	// Note that instead of passing digit
	// number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

int getMax_compare(int arr[], int n, int& countCmp)
{
	int mx = arr[0];
	for (int i = 1; ++countCmp && i < n; i++)
		if (++countCmp && arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countSort_compare(int arr[], int n, int exp, int& countCmp)
{
	int* output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; ++countCmp && i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; ++countCmp && i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; ++countCmp && i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; ++countCmp && i < n; i++)
		arr[i] = output[i];
	delete[] output;
}

void radixSort_compare(int arr[], int n, int& countCmp)
{
	countCmp = 0;
	int m = getMax_compare(arr, n, countCmp);
	for (int exp = 1; ++countCmp && m / exp > 0; exp *= 10)
		countSort_compare(arr, n, exp, countCmp);
}