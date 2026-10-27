#ifndef NODE_H
#define NODE_H

#include "Job.h"

// Custom Node for Linked List Queue Implementation (No STL used)
struct Node {
    Job job;
    Node* next;

    explicit Node(Job j) : job(std::move(j)), next(nullptr) {}
};

#endif 