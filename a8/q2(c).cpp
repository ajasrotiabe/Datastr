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
    if (!root) return nullptr;
    while (root->left)
        root = root->left;
    return root;
}
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
Node* minNode = find_min(root);
    if (minNode)
        cout << "Minimum element is " << minNode->data << endl;

    return 0;
}
