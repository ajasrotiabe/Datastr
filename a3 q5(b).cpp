#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    stack<int> S;
    S.push(3);
    S.push(1);
    S.push(2);
vector<int> B;
while (!S.empty()) {
        B.push_back(S.top());
        cout << "Moved " << S.top() << " from Stack to B" << endl;
        S.pop();
    }
cout << "Array B: ";
    for (int x : B) cout << x << " ";
    return 0;
}
