#include <iostream>
#include <vector>

using namespace std;

// sturcture node
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

int main() {
    Node* root = new Node('A');

    Node* b = new Node('B');
    Node* c = new Node('C');
    Node* d = new Node('D');
    Node* e = new Node('E');
    Node* f = new Node('F');
    Node* g = new Node('G');

    Node* h = new Node('H');
    Node* i = new Node('I');
    Node* j = new Node('J');
    Node* k = new Node('K');
    Node* l = new Node('L');
    Node* m = new Node('M');
    Node* n = new Node('N');

    Node* p = new Node('P');
    Node* q = new Node('Q');

    // cnnect level 1 nodes to Root 'A'
    addChild(root, b);
    addChild(root, c);
    addChild(root, d);
    addChild(root, e);
    addChild(root, f);
    addChild(root, g);

    //connect level 2 nodes
    addChild(d, h);

    addChild(e, i);
    addChild(e, j);
    addChild(f, k);
    addChild(f, l);
    addChild(f, m);
    addChild(g, n);
    addChild(j, p);
    addChild(j, q);

    cout << "Tree successfully created!" << endl;

    return 0;
}