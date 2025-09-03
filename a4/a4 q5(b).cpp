#include <iostream>
#include <queue>
using namespace std;
class StackOneQueue {
    queue<int> q;
public:
void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << "Pushed: " << x << "\n";
    }
void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << "\n";
        q.pop();
    }
void top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << q.front() << "\n";
    }
bool isEmpty() {
        return q.empty();
    }
};
int main() {
    StackOneQueue stack;
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