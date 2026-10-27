#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char data;
    vector<Node*> children; 

    Node(char val) {
        data = val;
    }
};

void addChild(Node* parent, Node* child) {
    if (parent != nullptr && child != nullptr) {
        parent->children.push_back(child);
    }
}

#endif