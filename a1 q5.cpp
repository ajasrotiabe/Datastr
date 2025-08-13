#include <iostream>
using namespace std;

void sol(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
        cout << "Sum of row " << i + 1 << " is: " << sum << endl;
    }

    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += arr[i][j];
        }
        cout << "Sum of column " << j + 1 << " is: " << sum << endl;
    }
}

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol(arr);
}
