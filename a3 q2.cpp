#include <iostream>
#include <stack>
using namespace std;
string reverseString(string str) {
    stack<char> s;
    for (char c : str) s.push(c);
string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    return rev;
}
int main() {
    string input = "DataStructure";
    cout << "Original String: " << input << endl;
    cout << "Reversed String: " << reverseString(input) << endl;
    return 0;
}
