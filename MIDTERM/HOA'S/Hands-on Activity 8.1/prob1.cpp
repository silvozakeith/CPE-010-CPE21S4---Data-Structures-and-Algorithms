#include <iostream>
#include "sorting.h" 

using namespace std;

int main() {
    int arr[] = {48, 21, 10, 15, 57, 29};
    int n = 6;

    int pivot = arr[n - 1];
    int i = -1;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[n - 1]);
    int pivotIndex = i + 1; 
    shellSort(arr, pivotIndex);
    shellSort(arr + pivotIndex + 1, n - pivotIndex - 1);

    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    return 0;
}