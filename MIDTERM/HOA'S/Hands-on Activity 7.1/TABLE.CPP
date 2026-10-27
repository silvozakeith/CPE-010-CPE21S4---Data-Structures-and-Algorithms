#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 100;

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

// Bubble Sort
void bubbleSort(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Routine Smallest for Selection Sort
int Routine_Smallest(int A[], int K, int arrSize) {
    int position = K;
    int smallestElem = A[K];

    for (int J = K + 1; J < arrSize; J++) {
        if (A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}

// Selection Sort Main Function
void selectionSort(int arr[], int N) {
    int POS, temp;
    for (int i = 0; i < N; i++) {
        POS = Routine_Smallest(arr, i, N);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int N) {
    int K = 1;
    while (K < N) {
        int temp = arr[K];
        int J = K - 1;

        while (J >= 0 && temp < arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        K++;
    }
}

int main() {
    srand(time(0));

    int originalArray[SIZE];
    int workArray[SIZE];

    generateRandomArray(originalArray, SIZE);

    cout << "Table 7-1: Original Unsorted Array (100 elements)" << endl;
    printArray(originalArray, SIZE);
    cout << endl;

    copyArray(originalArray, workArray, SIZE);
    bubbleSort(workArray, SIZE);
    cout << "Table 7-2: Bubble Sort Output" << endl;
    printArray(workArray, SIZE);
    cout << endl;

    copyArray(originalArray, workArray, SIZE);
    selectionSort(workArray, SIZE);
    cout << "Table 7-3: Selection Sort Output" << endl;
    printArray(workArray, SIZE);
    cout << endl;

    copyArray(originalArray, workArray, SIZE);
    insertionSort(workArray, SIZE);
    cout << "Table 7-4: Insertion Sort Output" << endl;
    printArray(workArray, SIZE);
    cout << endl;

    return 0;
}