#include <iostream>
#include <string>
#include <limits>
#include "node.h"
#include "searchingAlgo.h"

using namespace std;

struct Student {
    int id;
    string name;

    bool operator==(const Student& other) const {
        return id == other.id;
    }
};

int main() {
    int searchID;
    int findVal;

    cout << "Enter Student ID to search: ";
    cin >> searchID;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter integer to binary search: ";
    cin >> findVal;

    cout << "\n--- RESULTS ---\n";

    const int STUDENT_COUNT = 5;
    Student students[STUDENT_COUNT] = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"},
        {104, "David"},
        {105, "Eve"}
    };

    Student targetStudent = {searchID, ""};
    cout << "Array Search: ";
    linearSearchArr(STUDENT_COUNT, targetStudent, students);

    Node<int>* head = new_node(10);
    Node<int>* n2 = new_node(20);
    Node<int>* n3 = new_node(30);
    Node<int>* n4 = new_node(40);
    Node<int>* n5 = new_node(50);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    cout << "Linked List Binary Search: ";
    binarySearchLL(head, findVal);

    return 0;
}