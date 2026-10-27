#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Stack.h"
#include "Queue.h"

bool verifyReverseOrder(ArrayStack& stack, LinkedQueue& queue) {
    bool isValid = true;
    while (!stack.isEmpty() && !queue.isEmpty()) {
        if (stack.top() != queue.front()) {
            isValid = false;
        }
        stack.pop();
        queue.dequeue();
    }
    return isValid;
}

void runTestCase(const std::string& inputSequence) {
    ArrayStack stack;
    LinkedQueue queue;
    std::stringstream ss(inputSequence);
    int customerNumber;

    while (ss >> customerNumber) {
        stack.push(customerNumber);
        queue.enqueue(customerNumber);
    }

    bool result = verifyReverseOrder(stack, queue);

    std::cout << "Customer Number : " << inputSequence << "\n";
    std::cout << "Valid : " << (result ? "Yes" : "No") << "\n";
}

int main() {
    std::cout << "Customer Service Verification System\n\n";

    std::vector<std::string> testCases = {
        "101 102 103 102 101",
        "101 102 103",
        "205 205",
        "501",
        "10 20 30 40 50",
        "11 22 33 22 11"
    };

    for (const auto& test : testCases) {
        runTestCase(test);
    }

    return 0;
}