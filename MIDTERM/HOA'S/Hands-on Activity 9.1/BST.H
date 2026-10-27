#ifndef BST_H
#define BST_H

#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    T key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

public:
    // constructor
    BinarySearchTree(T value);
    void insert(T value);

    // traversing algo
    void preOrder();
    void inOrder();
};

// constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

// insert
template <typename T>
void BinarySearchTree<T>::insert(T value) {
    if (value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value);
        } else {
            left->insert(value);
        }
    } else if (value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
        } else {
            right->insert(value);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder() {
    std::cout << key << " ";
    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder() {
    // got to left
    if (left != nullptr) {
        left->inOrder();
    }
    std::cout << key << " ";

    // go to right
    if (right != nullptr) {
        right->inOrder();
    }
}

#endif