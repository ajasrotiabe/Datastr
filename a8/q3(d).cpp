#include <iostream>
#include <algorithm>
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
int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}
int main() {
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
cout << "Minimum depth of BST: " << minDepth(root) << endl;
    return 0;
}
