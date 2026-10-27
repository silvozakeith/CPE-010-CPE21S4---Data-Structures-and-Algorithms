#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Function to display queue contents by value (copies queue so original is untouched)
void display(queue<string> q) {
    while (!q.empty()) {
        cout << "\t" << q.front();
        q.pop();
    }
    cout << endl;
}

int main() {
    // Array of student names
    string studentArray[] = {"KEITH", "NICOLE", "BONDOC", "BONDOC", "Star"};
    int n = sizeof(studentArray) / sizeof(studentArray[0]);

    // Instantiate C++ STL Queue of strings
    queue<string> studentQueue;

    // Enqueue array elements into the queue
    for (int i = 0; i < n; i++) {
        studentQueue.push(studentArray[i]);
    }

    // Display initial queue
    cout << "The queue is :";
    display(studentQueue);

    // Queue member functions
    cout << "a.empty() : " << studentQueue.empty() << endl;
    cout << "a.size()  : " << studentQueue.size() << endl;
    cout << "a.front() : " << studentQueue.front() << endl;
    cout << "a.back()  : " << studentQueue.back() << endl;

    // Pop front element
    cout << "a.pop()   : ";
    studentQueue.pop();
    display(studentQueue);

    // Push new element
    studentQueue.push("Keith");
    cout << "The queue is :";
    display(studentQueue);

    return 0;
}