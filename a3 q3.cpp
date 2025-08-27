#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string expr) {
    stack<char> s;
for (char c : expr) {
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;

            char top = s.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
if (isBalanced(exp))
        cout << "Expression is Balanced" << endl;
    else
        cout << "Expression is NOT Balanced" << endl;

    return 0;
}
