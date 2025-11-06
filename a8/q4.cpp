#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool isBSTUtil(Node* root, Node*& prev) {
    if (!root) return true;
    if (!isBSTUtil(root->left, prev)) return false;
    if (prev && root->data <= prev->data) return false;
    prev = root;
    return isBSTUtil(root->right, prev);
}
bool isBST(Node* root) {
    Node* prev = nullptr;
    return isBSTUtil(root, prev);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
if (isBST(root))
        cout << "Given tree IS a BST\n";
    else
        cout << "Given tree is NOT a BST\n";
    root->right->left = new Node(3);
    if (isBST(root))
        cout << "Given tree IS a BST\n";
    else
        cout << "Given tree is NOT a BST\n";

    return 0;
}
