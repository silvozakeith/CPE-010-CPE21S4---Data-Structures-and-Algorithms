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
    if (parent && child) {
        parent->children.push_back(child);
    }
}

// pre order
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    for (Node* child : root->children) {
        preOrder(child);
    }
}

// post order
void postOrder(Node* root) {
    if (!root) return;
    for (Node* child : root->children) {
        postOrder(child);
    }
    cout << root->data << " ";
}

// in order
void inOrder(Node* root) {
    if (!root) return;
    if (!root->children.empty()) inOrder(root->children[0]);
    cout << root->data << " ";
    for (size_t i = 1; i < root->children.size(); i++) {
        inOrder(root->children[i]);
    }
}

// findData fuction
bool found = false;

void search(Node* root, char key) {
    if (!root || found) return;
    if (root->data == key) {
        found = true;
        return;
    }
    for (Node* child : root->children) {
        search(child, key);
    }
}

void findData(int CHOICE, char KEY, Node* root) {
    found = false;
    search(root, KEY);
    if (found) {
        cout << KEY << " was found!" << endl;
    }
}

int main() {
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');
    Node* K = new Node('K');
    Node* L = new Node('L');
    Node* M = new Node('M');
    Node* N = new Node('N');
    Node* P = new Node('P');
    Node* Q = new Node('Q');

    addChild(A, B); addChild(A, C); addChild(A, D);
    addChild(A, E); addChild(A, F); addChild(A, G);
    addChild(D, H);
    addChild(E, I); addChild(E, J);
    addChild(F, K); addChild(F, L); addChild(F, M);
    addChild(G, N);
    addChild(J, P); addChild(J, Q);

    cout << "Pre-order:  "; preOrder(A);  cout << endl;
    cout << "Post-order: "; postOrder(A); cout << endl;
    cout << "In-order:   "; inOrder(A);   cout << endl;

    cout << "\nSearching J: ";
    findData(1, 'J', A);

    Node* O = new Node('O');
    addChild(G, O);
    cout << "Searching O: ";
    findData(1, 'O', A);

    return 0;
}