#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}
void insertAtEnd(int v) {
    struct Node* n = createNode(v);
    if (!head) {
        head = n;
        return;
    }
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}
void searchNode(int key) {
    struct Node* t = head;
    int pos = 1;
    while (t) {
        if (t->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        t = t->next;
        pos++;
    }
    printf("Not found\n");
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    searchNode(20);
    searchNode(40);
}
