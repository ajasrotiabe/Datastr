#include <iostream>
using namespace std;
class SimpleQueue {
    int *queue, front, rear, max_size;
public:
    SimpleQueue(int size = 5) {
        max_size = size;
        queue = new int[max_size];
        front = 0;
        rear = 0;
    }
    ~SimpleQueue() {
        delete[] queue;
    }
    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return rear == max_size;
    }
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        queue[rear++] = item;
        cout << "Enqueued: " << item << "\n";
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int item = queue[front++];
        cout << "Dequeued: " << item << "\n";
        if (front == rear) front = rear = 0;
        return item;
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << queue[front] << "\n";
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i < rear; i++) cout << queue[i] << " ";
        cout << "\n";
    }
};
int main() {
    SimpleQueue q;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.IsEmpty 4.IsFull 5.Display 6.Peek 7.Exit\nChoice: ";
        int c; cin >> c;
        if (c == 1) {
            int x; cout << "Enter element: "; cin >> x;
            q.enqueue(x);
        }
        else if (c == 2) q.dequeue();
        else if (c == 3) cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
        else if (c == 4) cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
        else if (c == 5) q.display();
        else if (c == 6) q.peek();
        else if (c == 7) break;
        else cout << "Invalid choice!\n";
    }
}