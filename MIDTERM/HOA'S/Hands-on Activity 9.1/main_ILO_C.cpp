#include <iostream>

using namespace std;

// structure node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// bst insert
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// in order
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// pr eorder
void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// post order
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 18);
    root = insert(root, 0);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 5);

    cout << "In order:";
    inOrder(root);
    cout << endl;

    cout << "Pre order: ";
    preOrder(root);
    cout << endl;

    cout << "Post order: ";
    postOrder(root);
    cout << endl;

    return 0;
}