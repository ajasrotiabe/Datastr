#include <iostream>
#include <stack>
using namespace std;
class SpecialStack {
    stack<int> st;
    int minEle;
public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minEle = x;
        } else if (x < minEle) {
            st.push(2*x - minEle);
            minEle = x;
        } else {
            st.push(x);
        }
    }
    void pop() {
        if (st.empty()) return;
        int t = st.top(); st.pop();
        if (t < minEle) minEle = 2*minEle - t;
    }
    int top() {
        if (st.empty()) return -1;
        int t = st.top();
        return (t < minEle) ? minEle : t;
    }
    int getMin() {
        if (st.empty()) return -1;
        return minEle;
    }
};
int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}
