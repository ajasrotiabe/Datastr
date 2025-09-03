#include <iostream>
using namespace std;
class CircularQueue {
    int *queue, front, rear, max_size;
public:
    CircularQueue(int size = 5) {
        max_size = size;
        queue = new int[max_size];
        front = -1;
        rear = -1;
    }
    ~CircularQueue() {
        delete[] queue;
    }
bool isEmpty() {
        return front == -1;
    }
bool isFull() {
        return (rear + 1) % max_size == front;
    }
void enqueue(int item) {
        if (isFull()) {
            cout << "Circular Queue is full!\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % max_size;
        queue[rear] = item;
        cout << "Enqueued: " << item << "\n";
    }
int dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty!\n";
            return -1;
        }
        int item = queue[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % max_size;
        cout << "Dequeued: " << item << "\n";
        return item;
    }
void peek() {
        if (isEmpty()) {
            cout << "Circular Queue is empty!\n";
            return;
        }
        cout << "Front element: " << queue[front] << "\n";
    }
void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty!\n";
            return;
        }
        cout << "Circular Queue contents: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % max_size;
        }
        cout << "\n";
    }
};
int main() {
    CircularQueue q;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.IsEmpty 4.IsFull 5.Display 6.Peek 7.Exit\nChoice: ";
        int c; cin >> c;
        if (c == 1) {
            int x; cout << "Enter element: "; cin >> x;
            q.enqueue(x);
        }
        else if (c == 2) q.dequeue();
        else if (c == 3) cout << (q.isEmpty() ? "Circular Queue is empty.\n" : "Circular Queue is not empty.\n");
        else if (c == 4) cout << (q.isFull() ? "Circular Queue is full.\n" : "Circular Queue is not full.\n");
        else if (c == 5) q.display();
        else if (c == 6) q.peek();
        else if (c == 7) break;
        else cout << "Invalid choice!\n";
    }
}