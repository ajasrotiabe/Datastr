#include <iostream>
#include <queue>
using namespace std;
void interleaveQueue(queue<int> &q) {
int n = q.size();
if (n % 2 != 0) {
        cout << "Queue size should be even for interleaving.\n";
        return;
    }
int half = n / 2;
 queue<int> firstHalf;
for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}
int main() {
    queue<int> q;
    cout << "Enter queue elements separated by space (end input with non-integer): ";
    int x;
while (cin >> x) {
        q.push(x);
    }
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

interleaveQueue(q);

cout << "Interleaved queue: ";
while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}