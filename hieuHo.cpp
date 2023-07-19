#include "hieuHo.h"
#include "DataGenerator.h"
#include <iostream>
#include <cmath>
#include <time.h>
#include <cstring>

using namespace std;



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

void insertionSort_compare(int a[], int n, long long& count_compare)
{
	for (int i = 1; ++count_compare && i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (++count_compare && j >= 0 && ++count_compare && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void flashSort_compare(int a[], int n, long long& count_compare)
{
	count_compare = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++count_compare && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_compare && i < n; i++)
	{
		if (++count_compare && a[i] < minVal)
			minVal = a[i];
		if (++count_compare && a[i] > a[max])
			max = i;
	}
	if (++count_compare && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++count_compare && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++count_compare && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++count_compare && nmove < n - 1)
	{
		while (++count_compare && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++count_compare && k < 0) break;
		while (++count_compare && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort_compare(a, n, count_compare);
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
void radixSort_time(int arr[], int n, double& time)
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

int getMax_compare(int arr[], int n, long long& count_compare)
{
	int mx = arr[0];
	for (int i = 1; ++count_compare && i < n; i++)
		if (++count_compare && arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countSort_compare(int arr[], int n, int exp, long long& count_compare)
{
	int* output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; ++count_compare && i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; ++count_compare && i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; ++count_compare && i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; ++count_compare && i < n; i++)
		arr[i] = output[i];
	delete[] output;
}

void radixSort_compare(int arr[], int n, long long& count_compare)
{
	count_compare = 0;
	int m = getMax_compare(arr, n, count_compare);
	for (int exp = 1; ++count_compare && m / exp > 0; exp *= 10)
		countSort_compare(arr, n, exp, count_compare);
}

void flashSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
	time = 0;
	count_compare = 0;

	if (typeCount == COMPARE || typeCount == BOTH)
		flashSort_compare(a, n, count_compare);
	if (typeCount == TIME || typeCount == BOTH)
		flashSort_time(a, n, time);
}

void radixSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
	time = 0;
	count_compare = 0;

	if (typeCount == COMPARE || typeCount == BOTH)
		radixSort_compare(a, n, count_compare);
	if (typeCount == TIME || typeCount == BOTH)
		radixSort_time(a, n, time);
}