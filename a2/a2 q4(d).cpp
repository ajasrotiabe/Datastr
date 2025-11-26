#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << "Sorted strings: ";
    for (auto &s : arr) cout << s << " ";
    cout << endl;
    return 0;
}