/*
 * Title: hw5_2.cpp
 * Abstract: This program displays the performance of three
 *           different sorting algorithms (= heap sort, merge sort, and quick sort)
 *           on the screen.
 * Author: Justin Mello
 * ID: 2002
 * Date: 04/13/2021
 * Citations: Heap sort functions used from https://www.geeksforgeeks.org/heap-sort/.
 *            Merge sort functions used from https://www.geeksforgeeks.org/merge-sort/.
 *            Quick sort functions used from https://www.geeksforgeeks.org/quick-sort/.
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>
using namespace std;
using namespace std::chrono;

int userInput;

//Used from https://www.geeksforgeeks.org/heap-sort/
void swap(int* a, int* b) {

    int t = *a;
    *a = *b;
    *b = t;
}

//Used from https://www.geeksforgeeks.org/heap-sort/
void heapify( int arr[], int i) {

    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < userInput && arr[l] < arr[smallest])
        smallest = l;


    if (r < userInput && arr[r] < arr[smallest])
        smallest = r;


    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, smallest);
    }
}

//https://www.geeksforgeeks.org/heap-sort/
void buildHeap(int arr[]) {

    for (int i = userInput; i >= 0; i--) {
        heapify(arr, i);
    }
}

//Used from https://www.geeksforgeeks.org/merge-sort/
void merge(int arr[], int l, int m, int r) {

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    int i = 0;

    int j = 0;

    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Used from https://www.geeksforgeeks.org/merge-sort/.
void mergeSort(int arr[], int l, int r) {

    if(l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

//Used from https://www.geeksforgeeks.org/quick-sort/
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//Used from https://www.geeksforgeeks.org/quick-sort/
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

auto calcHeapTime(int arr[]) {

    //Start
    auto started = high_resolution_clock::now();

    //Sort
    buildHeap(arr);

    //Stop and return time
    auto done = high_resolution_clock::now();
    duration<double> time_total = duration_cast<duration<double>>(done-started);

    return time_total.count();
}

auto calcMergeTime(int arr[]) {

    //Start
    auto started = high_resolution_clock::now();

    //Sort
    mergeSort(arr, 0, userInput - 1);

    //Stop and return time
    auto done = high_resolution_clock::now();
    duration<double> time_total = duration_cast<duration<double>>(done-started);

    return time_total.count();
}

auto calcQuickTime(int arr[]) {

    //Start
    auto started = high_resolution_clock::now();

    //Sort
    quickSort(arr, 0, userInput - 1);

    //Stop and return time
    auto done = high_resolution_clock::now();
    duration<double> time_total = duration_cast<duration<double>>(done-started);

    return time_total.count();
}

int main() {

    default_random_engine randomNum;
    uniform_int_distribution<int> distribution(1,10'000'000);
    auto roll = std::bind(distribution, randomNum);

    cout << "Enter input size: ";
    cin >> userInput;

    int* array = new int[userInput];
    generate(array, array + userInput, roll);

    cout << "===================== Execution Time ====================" << endl;
    cout << "Heap sort:    " << calcHeapTime(array)  << "  milliseconds" << endl;
    generate(array, array + userInput, roll);

    cout << "Merge sort:   " << calcMergeTime(array) << "  milliseconds" << endl;
    generate(array, array + userInput, roll);

    cout << "Quick sort:   " << calcQuickTime(array) << "  milliseconds" << endl;
    cout << "=========================================================" << endl;

    //Delete array after calculations complete
    delete []array;
}
