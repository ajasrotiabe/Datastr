#include <iostream>
#include <stack>
using namespace std;
int evaluatePostfix(string exp) {
    stack<int> s;
for (char c : exp) {
        if (isdigit(c)) {
            s.push(c - '0'); // convert char digit to int
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}
int main() {
    string postfix;
    cout << "Enter postfix expression (single digits): ";
    cin >> postfix;
    cout << "Evaluated Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}
