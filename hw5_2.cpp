/*
 * Title: hw5_2.cpp
 * Abstract: This program displays the performance of three
 *           different sorting algorithms (= heap sort, merge sort, and quick sort)
 *           on the screen.
 * Author: Justin Mello
 * ID: 2002
 * Date: 04/13/2021
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>
using namespace std;
using namespace std::chrono;

int input; // size of array

void swap(int* a, int* b) {

    int t = *a;
    *a = *b;
    *b = t;
}

void heapify( int arr[], int i) {

    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < input && arr[l] < arr[smallest])
        smallest = l;


    if (r < input && arr[r] < arr[smallest])
        smallest = r;


    if (smallest != i) {
        swap(arr[i], arr[smallest]);


        heapify(arr, smallest);
    }
}


void buildHeap(int arr[]) {

    for (int i = input; i >= 0; i--) {
        heapify(arr, i);
    }
}

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

void mergeSort(int arr[], int l, int r) {

    if(l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

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


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

auto heapTime(int arr[]) {

    //Start
    auto started = high_resolution_clock::now();

    //Sort
    buildHeap(arr);

    //Stop and return time
    auto done = high_resolution_clock::now();
    duration<double> time_total = duration_cast<duration<double>>(done-started);

    return time_total.count();
}

auto mergeTime(int arr[]) {

    //Start
    auto started = high_resolution_clock::now();

    //Sort
    mergeSort(arr, 0, input - 1);

    //Stop and return time
    auto done = high_resolution_clock::now();
    duration<double> time_total = duration_cast<duration<double>>(done-started);

    return time_total.count();
}

auto quickTime(int arr[]) {

    //Start
    auto started = high_resolution_clock::now();

    //Sort
    quickSort(arr, 0, input - 1);

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
    cin >> input;

    int* array = new int[input];
    generate(array, array + input, roll);

    cout << "===================== Execution Time ====================" << endl;
    cout << "Heap sort:    " << heapTime(array)  << "  milliseconds" << endl;
    generate(array, array + input, roll);

    cout << "Merge sort:   " << mergeTime(array) << "  milliseconds" << endl;
    generate(array, array + input, roll);

    cout << "Quick sort:   " << quickTime(array) << "  milliseconds" << endl;
    cout << "=========================================================" << endl;

    //Delete array after calculations complete
    delete []array;
}
