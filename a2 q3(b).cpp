#include <iostream>
using namespace std;
int main() {
    int arr[] = {1,2,3,4,6,7,8};
    int n = 8;
    int low = 0, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Missing number (Binary Search): " << low + 1 << endl;
    return 0;
}
