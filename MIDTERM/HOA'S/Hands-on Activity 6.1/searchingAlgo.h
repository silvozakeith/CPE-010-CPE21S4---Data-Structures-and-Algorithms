#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
void linearSearchArr(int maxSize, T dataFind, T data[]) {
    for (int i = 0; i < maxSize; i++) {
        if (data[i] == dataFind) {
            cout << "Searching is sucessful\n";
            return;
        }
    }
    cout << "the search is unsuccessful\n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end) {
    if (start == nullptr) return nullptr;

    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {
    Node<T>* end = nullptr;

    while (start != end) {
        Node<T>* mid = getMiddle(start, end);

        if (mid == nullptr) break;

        if (mid->data == dataFind) {
            cout << "the data was found. \n";
            return;
        }
        
        if (mid->data < dataFind) {
            start = mid->next;
        } else {
            end = mid;
        }
    }
    cout << "Search element was not found\n";
}

#endif