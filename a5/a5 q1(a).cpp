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
void insertAtBeginning(int v) {
    struct Node* n = createNode(v);
    n->next = head;
    head = n;
}
void display() {
    struct Node* t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    display();
}
