#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    vector<int> A = {3, 1, 2};
    stack<int> S;
for (int x : A) {
        S.push(x);
        cout << "Pushed " << x << " into Stack" << endl;
    }
cout << "Stack (top to bottom): ";
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
    return 0;
}
