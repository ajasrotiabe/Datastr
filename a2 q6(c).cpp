#include <iostream>
#include <vector>
using namespace std;
int main() {
int r1, c1, t1; cin >> r1 >> c1 >> t1;
int r2, c2, t2; cin >> r2 >> c2 >> t2;
vector<vector<int>> A(t1, vector<int>(3)), B(t2, vector<int>(3));
for (int i = 0; i < t1; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];
for (int i = 0; i < t2; i++) cin >> B[i][0] >> B[i][1] >> B[i][2];
if (c1 != r2) { cout << "Not Possible"; return 0; }
vector<vector<int>> C;
for (int i = 0; i < t1; i++) {
for (int j = 0; j < t2; j++) {
if (A[i][1] == B[j][0]) C.push_back({A[i][0], B[j][1], A[i][2]*B[j][2]});
}
}
for (auto &r : C) cout << r[0] << " " << r[1] << " " << r[2] << endl;
return 0;
}