#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}
Node* search_recursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data)
        return search_recursive(root->left, key);
    else
        return search_recursive(root->right, key);
}
Node* search_iterative(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return nullptr;
}
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
int key = 40;
    cout << "Recursive search for " << key << ": ";
    Node* result = search_recursive(root, key);
    cout << (result ? "Found\n" : "Not found\n");

    key = 60;
    cout << "Iterative search for " << key << ": ";
    result = search_iterative(root, key);
    cout << (result ? "Found\n" : "Not found\n");

    return 0;
}

