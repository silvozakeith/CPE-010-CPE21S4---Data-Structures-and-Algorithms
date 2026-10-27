#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <iostream>
using namespace std;

// Doubly Linked List Node
template <typename T>
class DoubleList
{
public:
T data;
DoubleList<T>* next;
DoubleList<T>* prev;
};

// Create a new node
template <typename T>
DoubleList<T>* createNode(T newData)
{
DoubleList<T>* newNode = new DoubleList<T>;

newNode->data = newData;
newNode->next = nullptr;
newNode->prev = nullptr;

return newNode;
}

// Traverse the list
template <typename T>
void dllTraverse(DoubleList<T>* head)
{
if (head == nullptr)
{
cout << "The list is empty." << endl;
return;
}

DoubleList<T>* current = head;
cout << "List: ";
while (current != nullptr)
{
cout << current->data << " ";
current = current->next;
}
cout << endl;
}

// Insert at Head
template <typename T>
void dllInsertHead(T value, DoubleList<T>*& head)
{
DoubleList<T>* newNode = createNode(value);
newNode->next = head;
if (head != nullptr)
head->prev = newNode;
head = newNode;
}

// Insert at End
template <typename T>
void dllInsertEnd(T value, DoubleList<T>*& head)
{
DoubleList<T>* newNode = createNode(value);
if (head == nullptr)
{
head = newNode;
return;
}
DoubleList<T>* current = head;
while (current->next != nullptr)
current = current->next;
current->next = newNode;
newNode->prev = current;
}

// Insert After
template <typename T>
void dllInsertAfter(DoubleList<T>* prevNode, T value)
{
if (prevNode == nullptr)
return;

DoubleList<T>* newNode = createNode(value);

newNode->next = prevNode->next;
newNode->prev = prevNode;

if (prevNode->next != nullptr)
prevNode->next->prev = newNode;

prevNode->next = newNode;
}

// Delete a Node
template <typename T>
void dllDelete(T value, DoubleList<T>*& head)
{
if (head == nullptr)
return;
DoubleList<T>* current = head;
while (current != nullptr && current->data != value)
current = current->next;
if (current == nullptr)
return;
if (current == head)
head = current->next;
if (current->next != nullptr)
current->next->prev = current->prev;
if (current->prev != nullptr)
current->prev->next = current->next;
delete current;
}

#endif