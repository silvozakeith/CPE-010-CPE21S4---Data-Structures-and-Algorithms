#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>
using namespace std;

template <typename T>
class SinglyList
{
public:
    T data;
    SinglyList<T>* next;
};

template <typename T>
void ListTraversal(SinglyList<T>* node)
{
    while(node != nullptr)
    {
        cout << node->data;

        if(node->next != nullptr)
            cout << "->";

        node = node->next;
    }

    cout << endl;
}

template <typename T>
void sllInsertHead(T newData, SinglyList<T>** currentHead)
{
    SinglyList<T>* newNode = new SinglyList<T>;

    newNode->data = newData;
    newNode->next = *currentHead;

    *currentHead = newNode;
}

template <typename T>
void sllGeneralInsert(T newData, SinglyList<T>* prevNode)
{
    if(prevNode == nullptr)
    {
        cout << "Previous Node cannot be NULL!" << endl;
        return;
    }

    SinglyList<T>* newNode = new SinglyList<T>;

    newNode->data = newData;
    newNode->next = prevNode->next;

    prevNode->next = newNode;
}

template <typename T>
void sllInsertEnd(T newData, SinglyList<T>** head)
{
    SinglyList<T>* newNode = new SinglyList<T>;

    newNode->data = newData;
    newNode->next = nullptr;

    if(*head == nullptr)
    {
        *head = newNode;
        return;
    }

    SinglyList<T>* currentNode = *head;

    while(currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SinglyList<T>** head)
{
    SinglyList<T>* currNode = *head;
    SinglyList<T>* prevNode = nullptr;

    while(currNode != nullptr && currNode->data != findData)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == nullptr)
        return;

    if(prevNode == nullptr)
        *head = currNode->next;
    else
        prevNode->next = currNode->next;

    delete currNode;
}

#endif