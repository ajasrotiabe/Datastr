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
Node* find_min(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}
Node* inorder_successor(Node* root, Node* n) {
    if (n->right) return find_min(n->right);
    Node* succ = nullptr;
    while (root) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        } else if (n->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
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
    Node* succ = inorder_successor(root, n);
    if (succ)
        cout << "In-order successor of " << n->data << " is " << succ->data << endl;
    else
        cout << "No successor exists\n";

    return 0;
}
