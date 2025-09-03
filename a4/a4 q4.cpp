#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeatingChars(const string &s) {
    queue<char> q;
    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
        q.push(ch);
        while (!q.empty() && freq[q.front()] > 1) q.pop();
        if (!q.empty()) cout << q.front() << " ";
        else cout << -1 << " ";
    }
    cout << "\n";
}
int main() {
    cout << "Enter characters separated by space: ";
    string input, s;
    char ch;
    while (cin >> ch) {
        s.push_back(ch);
        if (cin.peek() == '\n') break;
    }
firstNonRepeatingChars(s);
}