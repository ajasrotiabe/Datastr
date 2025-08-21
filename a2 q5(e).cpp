#include <iostream>
#include <vector>
using namespace std;
int main() {
int n; cin >> n;
vector<int> sym(n*(n+1)/2);
for (int i = 0; i < sym.size(); i++) cin >> sym[i];
int k = 0;
vector<vector<int>> mat(n, vector<int>(n));
for (int i = 0; i < n; i++) {
for (int j = 0; j <= i; j++) mat[i][j] = sym[k++];
}
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
if (j > i) mat[i][j] = mat[j][i];
cout << mat[i][j] << " ";
}
cout << endl;
}
return 0;
}