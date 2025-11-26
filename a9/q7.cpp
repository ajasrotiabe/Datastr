#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;  // prev
    Node* right; // next
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void bstToDoublyList(Node* root, Node*& head, Node*& prev) {
    if (!root) return;
    bstToDoublyList(root->left, head, prev);
    if (prev) {
        prev->right = root;
        root->left = prev;
    } else {
        head = root;
    }
    prev = root;
    bstToDoublyList(root->right, head, prev);
}

Node* mergeTwoDLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    Node* head = nullptr;
    Node* tail = nullptr;
    while (head1 && head2) {
        Node* temp = nullptr;
        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->right;
        } else {
            temp = head2;
            head2 = head2->right;
        }
        temp->left = tail;
        if (tail) tail->right = temp;
        else head = temp;
        tail = temp;
    }
    while (head1) {
        head1->left = tail;
        if (tail) tail->right = head1;
        else head = head1;
        tail = head1;
        head1 = head1->right;
    }
    while (head2) {
        head2->left = tail;
        if (tail) tail->right = head2;
        else head = head2;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    // Build BST1: 20, 10, 30, 25, 100, 50
    Node* bst1 = new Node(20);
    bst1->left = new Node(10);
    bst1->right = new Node(30);
    bst1->right->left = new Node(25);
    bst1->right->right = new Node(100);
    bst1->right->left->left = new Node(50);

    // Build BST2: 5, 70
    Node* bst2 = new Node(5);
    bst2->right = new Node(70);

    Node* head1 = nullptr, *prev1 = nullptr;
    bstToDoublyList(bst1, head1, prev1);

    Node* head2 = nullptr, *prev2 = nullptr;
    bstToDoublyList(bst2, head2, prev2);

    Node* merged = mergeTwoDLL(head1, head2);
    printDLL(merged);
    return 0;
}
