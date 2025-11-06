#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};
Node* find_min(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;
root = deleteNode(root, 30);
    cout << "Inorder after deleting 30: ";
    inorder(root);
    cout << endl;
return 0;
}
