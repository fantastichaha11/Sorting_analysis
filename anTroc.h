#pragma once

void bubbleSort_countCompare(int* a, int n, int& count_compare);
void bubbleSort_countTime(int* a, int n, double& time);

void heapify_compare(int* a, int i, int n, int& count_compare);
void heapSort_countCompare(int* a, int n, int& count_compare);

void heapify_time(int* a, int i, int n);
void heapSort_countTime(int* a, int n, double& time);

int partition_compare(int arr[], int l, int r, int& count_compare);
void quickSort_compare(int* a, int l, int r, int& count_compare);
void quickSort_countCompare(int* a, int n, int& count_compare);

int partition_time(int arr[], int l, int r);
void quickSort_time(int* a, int l, int r);
void quickSort_countTime(int* a, int n, double& time);