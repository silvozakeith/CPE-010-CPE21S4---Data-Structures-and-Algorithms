#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

int main() {
    const int SIZE = 100;
    int originalArr[SIZE];
    int testArr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        originalArr[i] = rand() % 500 + 1;
    }

    cout << "TABLE 8-1: ARRAY OF VALUES FOR SORT ALGORITHM TESTING" << endl;
    cout << "Generated 100 Unsorted Random Elements:" << endl << endl;
    displayArray(originalArr, SIZE);

    copyArray(originalArr, testArr, SIZE);
    shellSort(testArr, SIZE);
    cout << "TABLE 8-2: SHELL SORT TECHNIQUE" << endl;
    cout << "Array Sorted using Shell Sort:" << endl << endl;
    displayArray(testArr, SIZE);

    copyArray(originalArr, testArr, SIZE);
    mergeSort(testArr, 0, SIZE - 1);
    cout << "TABLE 8-3: MERGE SORT ALGORITHM" << endl;
    cout << "Array Sorted using Merge Sort:" << endl << endl;
    displayArray(testArr, SIZE);

    copyArray(originalArr, testArr, SIZE);
    quickSort(testArr, 0, SIZE - 1);
    cout << "TABLE 8-4: QUICK SORT ALGORITHM" << endl;
    cout << "Array Sorted using Quick Sort:" << endl << endl;
    displayArray(testArr, SIZE);

    return 0;
}