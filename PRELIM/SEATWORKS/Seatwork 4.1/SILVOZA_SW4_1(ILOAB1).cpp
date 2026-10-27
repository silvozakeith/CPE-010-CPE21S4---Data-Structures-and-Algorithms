#include <iostream>

// global variables:
#define maxSize 10
int stackArr[maxSize];
int top = -1, newData;

// function prototypes:
// observer operators
bool isEmpty();
bool isFull();
void Top();        // the T is capital
void displayAll(); // goal is to display the stack following the LIFO principle

// transformer operators
void push();
void pop();

int main() {
    int choice;
    while (true) {
        std::cout << "===========================================\n";
        std::cout << " Stack operations: " << std::endl;
        std::cout << " [1] push [2] pop [3] isEmpty [4] isFull [5] Top [6] displayAll" << std::endl;
        std::cin >> choice;
        std::cout << "===========================================\n";

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                std::cout << "is the stack empty? " << isEmpty() << std::endl;
                break;
            case 4:
                std::cout << "is the stack full? " << isFull() << std::endl;
                break;
            case 5:
                Top();
                break;
            case 6:
                displayAll();
                break;
            default:
                std::cout << "Invalid Choice! " << std::endl;
                break;
        }
    }

    return 0;
}

// function definitions
bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == maxSize - 1);
}

void Top() {
    if (isEmpty()) return;
    std::cout << "The top element is: " << stackArr[top] << std::endl;
}

// goal is to display the stack following the LIFO principle
void displayAll() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    std::cout << "Stack elements (LIFO order): ";
    for (int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << " ";
    }
    std::cout << std::endl;
}

void push() {
    // error catching:
    if (isFull()) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }

    // ask the user what they want to insert:
    std::cout << " What number do you want to push? ";
    std::cin >> newData;

    // storing to the stack:
    stackArr[++top] = newData;
}

void pop() {
    // error catching:
    if (isEmpty()) return;

    // display the item to be popped:
    std::cout << "Popping: " << stackArr[top] << std::endl;

    // we remove the element from the stack
    top--;
}