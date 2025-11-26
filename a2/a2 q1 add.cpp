#include <iostream>
#include <unordered_map>
using namespace std;
int countPairsWithDiffK(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += freq[arr[i] - k] + freq[arr[i] + k];
        freq[arr[i]]++;
    }
    return count;
}
int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "Pairs with diff " << k << ": " << countPairsWithDiffK(arr, n, k) << endl;
    return 0;
}
