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
Node* find_max(Node* root) {
    while (root->right)
        root = root->right;
    return root;
}
Node* inorder_predecessor(Node* root, Node* n) {
    if (n->left) return find_max(n->left);
    Node* pred = nullptr;
    while (root) {
        if (n->data > root->data) {
            pred = root;
            root = root->right;
        } else if (n->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}
Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
Node* n = search(root, 30);
    Node* pred = inorder_predecessor(root, n);
    if (pred)
        cout << "In-order predecessor of " << n->data << " is " << pred->data << endl;
    else
        cout << "No predecessor exists\n";

    return 0;
}
