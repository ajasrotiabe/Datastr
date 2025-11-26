#include <iostream>
using namespace std;
#define MAX 5 
class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack." << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing on top." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
};
int main() {
    Stack st;
    int choice, value;

do {
        cout << "\n------ STACK MENU ------\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. IsEmpty?\n6. IsFull?\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.display();
                break;
            case 5:
                cout << (st.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 6:
                cout << (st.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
