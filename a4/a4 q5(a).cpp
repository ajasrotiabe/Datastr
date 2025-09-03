#include <iostream>
#include <queue>
using namespace std;
class StackTwoQueues {
    queue<int> q1, q2;
public:
void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << "Pushed: " << x << "\n";
    }
void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q1.front() << "\n";
        q1.pop();
    }
void top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << q1.front() << "\n";
    }
bool isEmpty() {
        return q1.empty();
    }
};
int main() {
    StackTwoQueues stack;
    while (true) {
        cout << "\n1.Push 2.Pop 3.Top 4.IsEmpty 5.Exit\nChoice: ";
        int c; cin >> c;
        if (c == 1) {
            int x; cout << "Enter element: "; cin >> x;
            stack.push(x);
        }
        else if (c == 2) stack.pop();
        else if (c == 3) stack.top();
        else if (c == 4) cout << (stack.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
        else if (c == 5) break;
        else cout << "Invalid choice!\n";
    }
}