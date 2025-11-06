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
int maxDepth(Node* root) {
    if (!root) return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return 1 + (left_depth > right_depth ? left_depth : right_depth);
}
int main() {
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 80);
cout << "Maximum depth of BST: " << maxDepth(root) << endl;
    return 0;
}
