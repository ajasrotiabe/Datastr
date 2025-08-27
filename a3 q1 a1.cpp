#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nearestSmaller(vector<int>& A) {
    stack<int> st;
    vector<int> ans;
    for (int x : A) {
        while (!st.empty() && st.top() >= x) st.pop();
        if (st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(x);
    }
    return ans;
}
int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> res = nearestSmaller(A);
    for (int x : res) cout << x << " ";
    return 0;
}
