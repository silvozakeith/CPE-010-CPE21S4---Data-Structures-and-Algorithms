#include <iostream>
#include "stackList.h"

int main() {
    std::cout << "--- Testing stack operations ---\n\n";

    // pushing elements
    push<int>(14);
    push<int>(41);
    push<int>(15);

    // displaying current top
    Top<int>();

    // displaying all elements
    displayALL<int>();

    // popping an element
    std::cout << "popped value: " << pop<int>() << "\n\n";

    // displaying stack after pop
    displayALL<int>();

    return 0;
}