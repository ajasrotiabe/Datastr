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
void deleteFromEnd() {
    if (!head) return;
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* t = head;
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
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
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    deleteFromEnd();
    display();
}
