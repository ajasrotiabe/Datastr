#include <iostream>
#include <vector>
using namespace std;
int main() {
int t1, t2; cin >> t1 >> t2;
vector<vector<int>> A(t1, vector<int>(3)), B(t2, vector<int>(3));
for (int i = 0; i < t1; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];
for (int i = 0; i < t2; i++) cin >> B[i][0] >> B[i][1] >> B[i][2];
vector<vector<int>> C;
C.insert(C.end(), A.begin(), A.end());
C.insert(C.end(), B.begin(), B.end());
for (auto &r : C) cout << r[0] << " " << r[1] << " " << r[2] << endl;
return 0;
}