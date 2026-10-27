#include<iostream>
#include <stack>


int main(){

// create an object:
std::stack<char> stack1;

std::cout<<"Is the Stack empty? "<<stack1.empty() <<std::endl;
stack1.push('K');
std::cout<<"Is the Stack empty? "<<stack1.top() <<std::endl;
stack1.push('I');
std::cout<<"current top of the stack: "<<stack1.top()<<std::endl;
stack1.push('T');
std::cout<<"current top of the stack: "<<stack1.top()<<std::endl;
std::cout<<"Is the stack empty? "<<stack1.empty()<<std::endl;
std::cout<<"What is the size of the stack? "<<stack1.size() <<std::endl;
 
//swap
std::stack<char> stack2;
    stack2.push('A');
    stack2.push('B');

    stack1.swap(stack2);

    std::cout<<"Top of stack1 after swap: "<<stack1.top()<<std::endl;
    std::cout<<"Top of stack2 after swap: "<<stack2.top()<<std::endl;

    // emplace
    stack1.emplace('Z');
    std::cout<<"Top of stack1 after emplace: "<<stack1.top()<<std::endl;
    std::cout<<"Size of stack1 after emplace: "<<stack1.size()<<std::endl;

    return 0;
}