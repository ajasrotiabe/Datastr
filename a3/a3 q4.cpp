#include <iostream>
#include <stack>
using namespace std;
int precedence(char opp) {
    if (opp == '+' || opp == '-') return 1;
    if (opp == '*' || opp == '/') return 2;
    if (opp == '^') return 3;
    return 0;
}
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // remove '('
        }
        else { // operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
 while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
return postfix;
}
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
