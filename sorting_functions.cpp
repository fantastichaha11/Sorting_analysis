#include "sorting_functions.h"

//Selection Sort
void selectionSort_countCompare(int* a, int n, long long& count_compare)
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
void selectionSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if (typeCount == COMPARE || typeCount == BOTH)
        selectionSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        selectionSort_countTime(a, n, time);
}
//Insertion Sort
void insertionSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
        insertionSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        insertionSort_countTime(a, n, time);
}
void insertionSort_countCompare(int* a, int n, long long& count_compare) {
    count_compare = 0;
    for (int i = 1; ++count_compare && i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (++count_compare && j >= 0 && ++count_compare && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void insertionSort_countTime(int* a, int n, double& time) {
    clock_t start, end;
    start = clock();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
//Bubble Sort
void bubbleSort_countCompare(int* a, int n, long long& count_compare)
{
    count_compare = 0;

    int i, j;
    bool swapped;
    for (i = 0; ++count_compare && i < n - 1; i++) {
        swapped = false;
        for (j = 0; ++count_compare && j < n - i - 1; j++) {
            if (++count_compare && a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (++count_compare && swapped == false)
            break;
    }
}
void bubbleSort_countTime(int* a, int n, double& time)
{
    clock_t start, end;

    start = clock();
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
void bubbleSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if (typeCount == COMPARE || typeCount == BOTH)
        bubbleSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        bubbleSort_countTime(a, n, time);
}
//Shaker Sort
void shakerSort(int* a, int n, long long& count_compare, double& time, int typeCount) {
    time = 0;
    count_compare = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
        shakerSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        shakerSort_countTime(a, n, time);
}
void shakerSort_countCompare(int* a, int n, long long& count_compare) { //Ref: geeksforgeeks
    count_compare = 0;
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;
        // loop from left to right same as the bubble sort
        for (int i = start; ++count_compare && i < end; i++) {
            if (++count_compare && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // if nothing moved, then array is sorted. otherwise, reset the swapped flag so that it can be used in the next stage
        if (!swapped)
            break;
        // move the end point back by one, because item at the end is in its rightful spot
        end--;
        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; ++count_compare && i >= start; i--) {
            if (++count_compare && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // increase the starting point, because the last stage would have moved the next smallest number to its rightful spot.
        ++start;
    }
}
void shakerSort_countTime(int* a, int n, double& time) { //Ref: geeksforgeeks
    clock_t begin, finish;
    begin = clock();
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;
        // loop from left to right same as the bubble sort
        for (int i = start; i < end; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // if nothing moved, then array is sorted. otherwise, reset the swapped flag so that it can be used in the next stage
        if (!swapped)
            break;
        // move the end point back by one, because item at the end is in its rightful spot
        end--;
        swapped = false;
        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; i--) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // increase the starting point, because the last stage would have moved the next smallest number to its rightful spot.
        ++start;
    }
    finish = clock();
    time = (double)(finish - begin) / CLOCKS_PER_SEC;
}
//Shell Sort
void shellSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
        shellSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        shellSort_countTime(a, n, time);
}
void shellSort_countCompare(int* a, int n, long long& count_compare)
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
//Heap sort
void heapify_compare(int* a, int i, int n, long long& count_compare)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;

    if ((++count_compare && l < n) && (++count_compare && a[l] > a[max]))
        max = l;

    if ((++count_compare && r < n) && (++count_compare && a[r] > a[max]))
        max = r;

    if (++count_compare && max != i)
    {
        swap(a[i], a[max]);
        heapify_compare(a, max, n, count_compare);
    }
}
void heapSort_countCompare(int* a, int n, long long& count_compare)
{
    count_compare = 0;
    for (int i = n / 2; ++count_compare && i >= 0; i--)
        heapify_compare(a, i, n, count_compare);

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify_compare(a, 0, i, count_compare);
    }
}
void heapify_time(int* a, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;

    if (l < n && a[l] > a[max])
        max = l;

    if (r < n && a[r] > a[max])
        max = r;

    if (max != i)
    {
        swap(a[i], a[max]);
        heapify_time(a, max, n);
    }
}
void heapSort_countTime(int* a, int n, double& time)
{
    clock_t start, end;
    start = clock();
    for (int i = n / 2; i >= 0; i--)
        heapify_time(a, i, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify_time(a, 0, i);
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
void heapSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if (typeCount == COMPARE || typeCount == BOTH)
        heapSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        heapSort_countTime(a, n, time);
}
//Merge Sort
void mergeSort(int* a, int n, long long& count_compare, double& time, int typeCount) {
    time = 0;
    count_compare = 0;
    if (typeCount == COMPARE || typeCount == BOTH)
        mergeSort_countCompare(a, 0, n - 1, count_compare);

    if (typeCount == TIME || typeCount == BOTH) {
        clock_t start, end;
        start = clock();
        mergeSort_countTime(a, 0, n - 1);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
    }
}
void merge_countCompare(int* a, int first, int mid, int last, long long& count_compare) {
    int* temp = new int[last + 1];
    int f1 = first, l1 = mid;
    int f2 = mid + 1, l2 = last;
    int i = first;
    while ((++count_compare && f1 <= l1) && (++count_compare && f2 <= l2)) {
        if (++count_compare && a[f1] <= a[f2]) {
            temp[i] = a[f1];
            f1++;
        }
        else {
            temp[i] = a[f2];
            f2++;
        }
        i++;
    }
    while (++ count_compare&& f1 <= l1) {
        temp[i] = a[f1];
        i++;
        f1++;
    }
    while (++count_compare && f2 <= l2) {
        temp[i] = a[f2];
        f2++;
        i++;
    }
    for (i = first; ++count_compare && i <= last; i++) {
        a[i] = temp[i];
    }
    delete[] temp;
}
void mergeSort_countCompare(int* a, int first, int last, long long& count_compare) {
    if (++count_compare && first >= last) {
        return;
    }
    int mid = first + (last - first) / 2;
    mergeSort_countCompare(a, first, mid, count_compare);
    mergeSort_countCompare(a, mid + 1, last, count_compare);
    merge_countCompare(a, first, mid, last, count_compare);
}
void merge_countTime(int* array, int left, int mid, int right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort_countTime(int* a, int first, int last) {
    if (first >= last) {
        return;
    }
    int mid = first + (last - first) / 2;
    mergeSort_countTime(a, first, mid);
    mergeSort_countTime(a, mid + 1, last);
    merge_countTime(a, first, mid, last);
}
//Quick sort
int partition_compare(int arr[], int l, int r, long long& count_compare)
{
    // Choosing the pivot
    int pivot = arr[r];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (l - 1);

    for (int j = l; ++count_compare && j <= r - 1; j++) {

        // If current element is smaller than the pivot
        if (++count_compare && arr[j] < pivot) {

            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}
void quickSort_compare(int* a, int l, int r, long long& count_compare)
{
    // Create an auxiliary stack
    int* stack = new int[r - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = r;

    // Keep popping from stack while is not empty
    while (++count_compare && top >= 0) {
        // Pop h and l
        r = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition_compare(a, l, r, count_compare);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (++count_compare && p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (++count_compare && p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
    delete[] stack;
}
void quickSort_countCompare(int* a, int n, long long& count_compare)
{
    count_compare = 0;

    quickSort_compare(a, 0, n - 1, count_compare);
}
int partition_time(int arr[], int l, int r)
{
    int pivot = arr[r];

    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {

        if (arr[j] < pivot) {

            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}
void quickSort_time(int* a, int l, int r)
{
    int* stack = new int[r - l + 1];

    int top = -1;

    stack[++top] = l;
    stack[++top] = r;

    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];

        int p = partition_time(a, l, r);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
    delete[] stack;
}
void quickSort_countTime(int* a, int n, double& time)
{
    clock_t start, end;
    start = clock();
    quickSort_time(a, 0, n - 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
void quickSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if (typeCount == COMPARE || typeCount == BOTH)
        quickSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        quickSort_countTime(a, n, time);
}
//Counting Sort
void countingSort(int* a, int n, long long& count_compare, double& time, int typeCount)
{
    time = 0;
    count_compare = 0;

    if (typeCount == COMPARE || typeCount == BOTH)
        countingSort_countCompare(a, n, count_compare);
    if (typeCount == TIME || typeCount == BOTH)
        countingSort_countTime(a, n, time);
}
void countingSort_countCompare(int* a, int n, long long& count_compare)
{
    count_compare = 0;
    int k = 0;

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

    for (int i = 0; ++count_compare && i < n; i++)
    {
        a[i] = S[i];
    }

    delete[]C;
    return;
}
void countingSort_countTime(int* a, int n, double& time)
{
    int k = 0;
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

    for (int i = 0; i < n; i++)
    {
        a[i] = S[i];
    }

    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    delete[]C;
    return;
}

//Hieu
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



