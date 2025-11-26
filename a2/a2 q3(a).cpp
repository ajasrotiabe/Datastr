#include <iostream>
using namespace std;
int main() {
    int arr[] = {1,2,3,4,6,7,8};
    int n = 8;
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += arr[i];
    cout << "Missing number (Linear): " << total - sum << endl;
    return 0;
}