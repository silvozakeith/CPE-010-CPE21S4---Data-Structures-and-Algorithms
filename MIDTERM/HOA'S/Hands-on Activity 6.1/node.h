#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* new_node(T value) {
    Node<T>* node = new Node<T>();
    node->data = value;
    node->next = nullptr;
    return node;
}

#endif