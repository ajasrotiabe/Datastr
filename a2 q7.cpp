#include <iostream>
#include <vector>
using namespace std;
int mergeAndCount(vector<int>& arr, int l, int m, int r) {
int n1 = m - l + 1, n2 = r - m;
vector<int> L(n1), R(n2);
for (int i = 0; i < n1; i++) L[i] = arr[l+i];
for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];
int i = 0, j = 0, k = l, inv = 0;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) arr[k++] = L[i++];
else { arr[k++] = R[j++]; inv += n1 - i; }
}
while (i < n1) arr[k++] = L[i++];
while (j < n2) arr[k++] = R[j++];
return inv;
}
int countInversions(vector<int>& arr, int l, int r) {
if (l >= r) return 0;
int m = l + (r-l)/2;
int inv = countInversions(arr, l, m);
inv += countInversions(arr, m+1, r);
inv += mergeAndCount(arr, l, m, r);
return inv;
}
int main() {
int n; cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];
cout << countInversions(arr, 0, n-1) << endl;
return 0;
}